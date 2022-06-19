%{
#include <stdio.h>
int yylex();
extern int yylineno;
extern FILE* yyin;
extern int yyerror (char* msg);
extern char * yytext;
%}

%start program
%token ASSIGNMENT OR AND EQUAL NOTEQUAL LESS LESSOREQUAL GREATER GREATEROREQUAL PLUS MINUS MULT DIV NOT DEF FED IF FI ELSE PRINT WHILE ELIHW INPUT TRUE FALSE RETURN INT_LITERAL DBL_LITERAL BOOLEAN STRING_LITERAL COMMENT ID OB CB INT DOUBLE COMMA COLON

%right ASSIGNMENT
%left OR
%left AND
%left EQUAL NOTEQUAL
%left LESS LESSOREQUAL GREATER GREATEROREQUAL
%left PLUS MINUS 
%left MULT DIV 
%right NOT

%%
//
program : function_list end_list
        ;

function_list : function_list function
              | function
              ;

function : DEF type ID OB parameters CB COLON statements FED
         | DEF type ID OB CB COLON statements FED
         ;

parameters : parameters COMMA type ID
           | type ID
           ;

type : INT
     | DOUBLE
     | BOOLEAN
     ;

statements : statements statement
           | statement
           ;

statement : assignment_stmt
          | print_stmt
          | input_stmt
          | condition_stmt
          | while_stmt
          | call_stmt
          | return_stmt
          | dec_stmt
          ;

assignment_stmt : ID ASSIGNMENT expression
                ;

dec_stmt : type ID
         ;

return_stmt : RETURN expression
            ;

expression : exp EQUAL exp
       | exp NOTEQUAL exp
       | exp LESS exp
       | exp LESSOREQUAL exp
       | exp GREATER exp
       | exp GREATEROREQUAL exp
       | exp
       ;

exp : exp PLUS exp
    | exp MINUS exp
    | exp MULT exp
    | exp DIV exp
    | exp OR exp
    | exp AND exp
    | NOT exp
    | factor
    ;

factor : INT_LITERAL
       | DBL_LITERAL
       | STRING_LITERAL
       | ID
       | TRUE
       | FALSE
       | call_stmt
       | OB exp CB
       ;

print_stmt : PRINT OB expression CB
           ;
input_stmt : ID ASSIGNMENT INPUT OB CB
           ;
call_stmt : ID OB CB
          | ID OB expr_list CB
          ;

condition_stmt : if_head statements FI
               | if_head statements ELSE COLON statements FI
               ;
if_head : IF expression COLON
        ;
while_stmt : WHILE expression COLON statements ELIHW;
expr_list : expr_list COMMA exp
          | exp
          ;

end_list : end_list end
         |end
         ;

end : call_stmt
    | print_stmt
    | input_stmt
    ;



%%
int main(int argc, char *argv[])
{
    // don't change this part
yyin = fopen(argv[1], "r" ) ; 
if(!yyparse())
        printf("\nParsing complete\n");
    else
        printf("\nParsing failed\n");
    
    fclose(yyin);

return 0;
}

extern int yyerror (char* msg)
{
printf("Syntax Error in Line : %d %s\n",(yylineno),yytext);
return 1;
}
