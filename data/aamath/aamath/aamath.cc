/* aamath.cc -- part of aamath
 *
 * This program is copyright (C) 2005 Mauro Persano, and is free
 * software which is freely distributable under the terms of the
 * GNU public license, included as the file COPYING in this
 * distribution.  It is NOT public domain software, and any
 * redistribution not permitted by the GNU General Public License is
 * expressly forbidden without prior written permission from
 * the author.
 *
 */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> // free()
#ifdef USE_READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif
#include "version.h"

static const char *aamath_prompt = "aamath> ";

#ifdef USE_READLINE
static char *line_read;
#endif
static char *cur_line_pos;
static bool eol_read;
static int line_len;

extern int yyparse();

bool interactive	= false;
bool quiet_mode		= false;
bool big_radicals	= true;
int (*get_input)(char *, int);

static int
get_input_from_buf(char *buf, int max_size)
{
	int rv;

	// XXX: fix the grammar so we don't need this ugly hack

	if (line_len == 0) {
		if (eol_read) {
			rv = 0;
		} else {
			// send a terminating '\n'
			rv = 1;
			buf[0] = '\n';
			eol_read = true;
		}
	} else {
		if (max_size > line_len)
			max_size = line_len;

		memcpy(buf, cur_line_pos, max_size);

		cur_line_pos += max_size;
		line_len -= max_size;

		rv = max_size;
	}

	return rv;
}

static int
get_input_from_stdin(char *buf, int max_size)
{
	int rv;

	if (interactive) {
		int c;

		if ((c = getchar()) == EOF) {
			rv = 0;
		} else {
			rv = 1;
			buf[0] = c;
		}
	} else {
		rv = fread(buf, 1, max_size, stdin);
	}

	return rv;
}

void
prompt()
{
#ifndef USE_READLINE
	if (interactive && !quiet_mode) {
		printf("%s", aamath_prompt);
		fflush(stdout);
	}
#endif
}

void
banner()
{
	if (!quiet_mode) {
		puts(VERSION);
		fflush(stdout);
	}
}

void
yyerror(const char *str, ...)
{
	va_list args;
	va_start(args, str);
	vprintf(str, args);

	putchar('\n');
}

int
render(int (*func)(char *, int))
{
	get_input = func;
	return yyparse();
}

void
usage()
{
	fprintf(stderr, VERSION" - ASCII art mathematics\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Usage: aamath [options]\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "Options are:\n");
	fprintf(stderr, "\n");
	fprintf(stderr, "  -r   narrower radicals\n");
	fprintf(stderr, "  -q   quiet mode\n");

	exit(1);
}

int
main(int argc, char *argv[])
{
	interactive = isatty(0);

	int c;

	while ((c = getopt(argc, argv, "rqh")) != EOF) {
		switch (c) {
			case 'r':
				big_radicals = false;
				break;

			case 'q':
				quiet_mode = true;
				break;

			case 'h':
			default:
				usage();
		}
	}

	int rv = 0;

	if (argc > optind) {
		do {
			cur_line_pos = argv[optind++];
			line_len = strlen(cur_line_pos);
			eol_read = false;
			rv |= render(get_input_from_buf);
		} while (argc > optind);
		return rv;
	}

	if (interactive) {
		banner();

#ifndef USE_READLINE
		prompt();

		rv = render(get_input_from_stdin);
#else
		const char *rl_prompt = quiet_mode ? "" : aamath_prompt;

		while ((line_read = readline(rl_prompt)) != NULL) {
			if (*line_read) {
				if (!strcmp(line_read, "quit")) {
					free(line_read);
					break;
				}

				add_history(line_read);

				cur_line_pos = line_read;
				line_len = strlen(line_read);
				eol_read = false;

				rv = render(get_input_from_buf);
			}

			free(line_read);
		}
#endif
	} else {
		rv = render(get_input_from_stdin);
	}

	return rv;
}
