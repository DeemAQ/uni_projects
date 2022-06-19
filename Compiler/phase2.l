%{
#include "phase2.h"
#include "phase2.tab.h"
#include <stdio.h>
extern int currentScope;

%}
/* KEEP TRACK OF LINE NUMBER*/
%option yylineno 
%%
"def"  { currentScope++; return(DEF);}
"fed"  {currentScope--; return(FED);}
"if"   {currentScope++; return(IF);}
"fi"   {currentScope--; return(FI);}
"else"   {return(ELSE);}
"print"   {return(PRINT);}
"while"   {currentScope++; return(WHILE);}
"elihw" {currentScope--; return(ELIHW);}
"input" {return(INPUT);}
"true" {return(_TRUE);}
"false" {return(_FALSE);}
"return" {return(RETURN);}
"int" {strcpy((yylval.symp).type,"int"); return INT;}
"double" {strcpy((yylval.symp).type,"double"); return DOUBLE;}
"boolean" {strcpy((yylval.symp).type,"boolean"); return BOOLEAN;}
"&&"  {return AND;}
"||"  {return OR;}
"!"   {return NOT;}
"*" {return(TIMES);}
"-" {return(MINUS);}
"+" {return(PLUS);}
"=" {return(ASS);}
"/" {return(DEV);}
"==" {return(EQ);}
"<" {return(LT);}
"<=" {return(LE);}
">" {return(GT);}
">=" {return(GE);}
"<>" {return(NE);}
"(" {return(LPAREN);}
")" {return(RPAREN);}
":" {return(COLON);}
"," {return(COMMA);}
[A-Z]([A-Za-z]|[0-9]|_)* {// assign name here 
    strcpy((yylval.symp).name,yytext); return(ID);}
\".*\" {strcpy(yylval.symp.type,"string"); return(STRING_LITERAL);}
[0-9]+ {strcpy((yylval.symp).type,"int"); return(INT_LITERAL);}
[0-9]+\.[0-9]+ {strcpy((yylval.symp).type,"double"); return(DBL_LITERAL);}

\n {} /*to update yylineno*/
"@"(.)*"@"\n {}
[ \t]+    {;}
.          {return 1; }// to exit parsing for any extra input 
%%
