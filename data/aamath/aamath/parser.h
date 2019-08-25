/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     REAL = 259,
     IDENTIFIER = 260,
     TRIGFN = 261,
     SQRT = 262,
     ROOT = 263,
     ELLIPSIS = 264,
     INF = 265,
     RANGE = 266,
     INT = 267,
     SUM = 268,
     PROD = 269,
     QUIT = 270,
     LIM = 271,
     PI = 272,
     NABLA = 273,
     ARROW = 274,
     DET = 275,
     ABS = 276,
     GTEQ = 277,
     LESSEQ = 278,
     NEG = 279
   };
#endif
/* Tokens.  */
#define INTEGER 258
#define REAL 259
#define IDENTIFIER 260
#define TRIGFN 261
#define SQRT 262
#define ROOT 263
#define ELLIPSIS 264
#define INF 265
#define RANGE 266
#define INT 267
#define SUM 268
#define PROD 269
#define QUIT 270
#define LIM 271
#define PI 272
#define NABLA 273
#define ARROW 274
#define DET 275
#define ABS 276
#define GTEQ 277
#define LESSEQ 278
#define NEG 279




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "parser.y"
{
	Constant *constval;
	Symbol *symval;
	Expression *expr;
	ExprVector *exprvec;
	FunctionArgs *args;
	Matrix *matrix;
	Matrix::Row *mrow;
}
/* Line 1529 of yacc.c.  */
#line 107 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

