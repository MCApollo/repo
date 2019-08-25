%{
/* parser.y -- part of aamath
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

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "expr.h"
#include "canvas.h"

// #undef __GNUC__ // stupid error with gcc 3.4.3 and bison 1.875 on djgpp combo

extern void prompt();
extern int yylex();
extern void yyerror(const char *str, ...);
%}

%union {
	Constant *constval;
	Symbol *symval;
	Expression *expr;
	ExprVector *exprvec;
	FunctionArgs *args;
	Matrix *matrix;
	Matrix::Row *mrow;
};

%token <constval> INTEGER REAL
%token <symval> IDENTIFIER TRIGFN
%token SQRT ROOT ELLIPSIS INF RANGE INT SUM PROD QUIT LIM PI NABLA ARROW
%token DET ABS
%right '=' '<' '>' LESSEQ GTEQ
%left '-' '+'
%left '*' '/'
%left NEG
%right '^'
%left '~'
%left '!' '\\'
%right '_'

%type <expr> expr
%type <symval> symbol opt_conj_symbol id subscr_id
%type <exprvec> subscr_id_list
%type <args> fn_args
%type <constval> constant
%type <matrix> matrix matrix_opt_det matrix_rows
%type <mrow> matrix_row

%%

input
: input	line			{ prompt(); }
| /* nothing */			{ }
;

line
: expr '\n' 			{ std::cout << "\n" << (*$1); delete $1; }
| error '\n' 			{ yyerrok; }
| QUIT '\n' 			{ YYACCEPT; }
| '\n'				{ std::cout << "\n"; }
;

expr
: constant			{ $$ = $1; }
| opt_conj_symbol		{ $$ = $1; }
| SQRT '(' expr ')'		{ $$ = new Sqrt($3); }
| ABS '(' expr ')'		{ $$ = new Abs($3); }
| ROOT '(' expr ',' expr ')'	{ $$ = new Root($3, $5); }
| INT '(' expr ',' expr ')'	{ $$ = new Integral($3, $5); }
| INT '(' expr ',' expr '=' expr RANGE expr ')'
	{ $$ = new IntegralOnInterval($3, $5, $7, $9); }
| SUM '(' expr ',' expr ')'	{ $$ = new Sum($3, $5); }
| SUM '(' expr ',' expr '=' expr RANGE expr ')'
	{ $$ = new SumOverInterval($3, $5, $7, $9); }
| PROD '(' expr ',' expr ')'	{ $$ = new Product($3, $5); }
| PROD '(' expr ',' expr '=' expr RANGE expr ')'
	{ $$ = new ProductOverInterval($3, $5, $7, $9); }
| LIM '(' expr ',' expr ARROW expr ')'
	{ $$ = new Limit($3, $5, $7); }
| opt_conj_symbol '(' fn_args ')'	{ $$ = new MultivarFunction($1, $3); }
| TRIGFN '(' expr ')' 			{ $$ = new TrigFunction($1, $3); }
| expr '=' expr			{ $$ = new Equal($1, $3); }
| expr '<' expr			{ $$ = new Less($1, $3); }
| expr '>' expr			{ $$ = new Greater($1, $3); }
| expr LESSEQ expr		{ $$ = new LessOrEqual($1, $3); }
| expr GTEQ expr		{ $$ = new GreaterOrEqual($1, $3); }
| expr '+' expr			{ $$ = new Add($1, $3); }
| expr '-' expr			{ $$ = new Sub($1, $3); }
| expr '*' expr			{ $$ = new Mul($1, $3); }
| expr '/' expr			{ $$ = new Div($1, $3); }
| '-' expr %prec NEG		{ $$ = new Neg($2); }
| '~' '(' expr ')'
	{
		Symbol *sym = dynamic_cast<Symbol *>($3);

		if (sym != NULL) {
			sym->switch_conj();
			$$ = $3;
		} else {
			$$ = new Conj($3);
		}
	}
| '(' expr ')' '\\'
	{
		Symbol *sym = dynamic_cast<Symbol *>($2);

		if (sym != NULL && sym->get_bar() == false) {
			sym->set_bar();
			$$ = $2;
		} else {
			$$ = new Bar($2);
		}
	}
| expr '^' expr
	{
		if ($1->accept_expn()) {
			$1->set_expn($3);
			$$ = $1;
		} else {
			$$ = new Pow($1, $3);
		}
	}
| expr '!'			{ $$ = new Fact($1); }
| '(' expr ')'			{ $$ = $2; }
| matrix_opt_det		{ $$ = $1; }
;

opt_conj_symbol
: symbol			{ $$ = $1; }
| '~' opt_conj_symbol		{ $2->switch_conj(); $$ = $2; }
;

symbol
: subscr_id			{ $$ = $1; }
| symbol '\''			{ $1->add_tick(); $$ = $1; }
| symbol '\\'			{ $1->set_bar(); $$ = $1; }
;

subscr_id
: subscr_id_list
	{
		Symbol *first, *prev;

		ExprVector::iterator i = $1->begin();

		first = prev = dynamic_cast<Symbol *>(*i++);

		while (i != $1->end()) {
			prev->set_subscr(*i);
			prev = dynamic_cast<Symbol *>(*i++);
		}

		delete $1;

		$$ = first;
	}
;

subscr_id_list
: id
	{
		$$ = new ExprVector();
		$$->push_back($1);
	}
| subscr_id_list '_' id			{ $1->push_back($3); $$ = $1; }
| subscr_id_list '_' '(' expr ')'	{ $1->push_back($4); $$ = $1; }
| subscr_id_list '_' constant		{ $1->push_back($3); $$ = $1; }
;

fn_args
: fn_args ',' expr		{ $1->add_arg($3); $$ = $1; }
| expr				{ $$ = new FunctionArgs(); $$->add_arg($1); }
;

constant
: INTEGER			{ $$ = $1; }
| REAL				{ $$ = $1; }
| ELLIPSIS			{ $$ = new Ellipsis(); }
| INF				{ $$ = new Infinity(); }
| PI				{ $$ = new Pi(); }
| NABLA				{ $$ = new Nabla(); }
;

id
: IDENTIFIER			{ $$ = $1; }
;

matrix_opt_det
: matrix			{ $$ = $1; }
| DET matrix 			{ $2->set_det(); $$ = $2; }
;

matrix
: '[' matrix_rows ']'		{ $$ = $2; }
;

matrix_rows
: matrix_row			{ $$ = new Matrix(); $$->add_row($1); }
| matrix_rows ';' matrix_row	{ $1->add_row($3); $$ = $1; }
;

matrix_row
: expr				{ $$ = new Matrix::Row(); $$->add_elem($1); }
| matrix_row ',' expr		{ $1->add_elem($3); $$ = $1; }
;

%%
