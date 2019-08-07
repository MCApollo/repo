#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define LDID "/usr/bin/ldid"
#define ENTS "/usr/share/entitlements/global.xml"

int main (int argc, char **argv) {
	int argcont;
	char *output;
	for (argcont = 0; argcont < argc - 1; argcont++) {
		if (!strcmp(argv[argcont], "-o")) {
			output = argv[argcont + 1];
		}
	}
	if (access(output, F_OK) == 0 && remove(output) == -1) {
		fprintf(stderr, "Unable to remove existing file: %s\n", strerror(errno));
		exit(-1);
	}
	extern char** environ;
	pid_t parent = getpid();
	pid_t pid = fork();
	int status;
	if (pid > 0) {
		waitpid(pid, &status, 0);
	} else if (pid == 0) {
		execve("/usr/bin/ld64_", argv, environ);
	} else {
		fprintf(stderr, "Unable to fork: %s\n", strerror(errno));
		exit(-1);
	}
	if (WEXITSTATUS(status) == 0 && access(output, R_OK|W_OK) == 0) {
		if (access(LDID, R_OK|X_OK) != 0) {
			fprintf(stderr, "Unable to execute ldid: %s\n", strerror(errno));
			return status;
		}
		char *entitlements = getenv("ENTITLEMENTS");
		if (entitlements == (char*)-1 || entitlements == NULL) {
			entitlements = ENTS;
		}
		if (access(entitlements, R_OK) != 0) {
			fprintf(stderr, "Entitlements at \"%s\" are not accessible: %s\n", entitlements, strerror(errno));
			return status;
		}
		parent = getpid();
		pid = fork();
		if (pid > 0) {
			waitpid(pid, &status, 0);
		} else if (pid == 0) {
			char entstr[strlen(entitlements)+3];
			entstr[0] = '-';
			entstr[1] = 'S';
			strcpy(entstr+2, entitlements);
			execl(LDID, LDID, entstr, output, NULL);
		} else {
			fprintf(stderr, "Unable to fork: %s\n", strerror(errno));
		}
	} else {
		fprintf(stderr, "Not signing file\n");
	}
	return WEXITSTATUS(status);
}
