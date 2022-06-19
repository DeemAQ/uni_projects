%{
#include <stdio.h>
#include <string.h>
void yyerror(char*);
#include "phase1.tab.h"
%}

/* KEEP TRACK OF LINE NUMBER*/
%option yylineno 

letter [A-Z a-z]
string ["]([^\"]|[\n])*[\"]
digit [0-9]
identifier [A-Z]({letter}|{digit}|_)*
integer_literal {digit}+
double_literal {digit}+'.'{digit}+

%%


"def" {return DEF;}
"fed" {return FED;}
"if" {return IF;}
"fi" {return FI;}
"else" {return ELSE;}
"print" {return PRINT;}
"while" {return WHILE;}
"elihw" {return ELIHW;}
"input" {return INPUT;}
"true" {return TRUE;}
"false" {return FALSE;}
"return" {return RETURN;}
"int" {return INT;}
"double" {return DOUBLE;}
"boolean" {return BOOLEAN;}

{integer_literal} {return INT_LITERAL;}
{double_literal} {return DBL_LITERAL;}
{identifier} {return ID;}
{string} {return STRING_LITERAL;}



'+' {return PLUS;}
'-' {return MINUS;}
'*' {return MULT;}
\/ {return DIV;}

"<>" { return NOTEQUAL;}
"==" { return EQUAL;}
">=" { return GREATEROREQUAL;}
">"  { return GREATER;}
"<=" { return LESSOREQUAL;}
"<" { return LESS;}

\|\| {return OR;}
'&&' {return AND;}
'!' {return NOT;}
'=' {return ASSIGNMENT;}

"(" {return OB;}
")" {return CB;}
',' {return COMMA;}
':' {return COLON;}




\n {} /*to update yylineno*/
"@"(.)*"@"\n {printf("COMMENT");}
[ \t]+    {}
. {;}
[" "]* {;} 
%%

int yywrap(void) 
{return 1;}