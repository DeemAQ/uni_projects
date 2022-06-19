%{
#include "phase2.h"
#include <stdio.h>
#include <string.h>
extern int yylineno;
extern FILE* yyin;
extern int yylex();
extern char* yytext;
extern int yyerror(char *msg);

int currentScope=0;
int varcount=0;
%}
%union {struct symbols symp;}

%token<symp>  STRING_LITERAL INT_LITERAL DBL_LITERAL ID _TRUE _FALSE

%token LPAREN RPAREN COLON COMMA

%token DEF FED IF FI ELSE PRINT WHILE ELIHW INPUT  RETURN

%token AND OR NOT TIMES MINUS PLUS ASS DEV EQ LT LE GT GE NE

%token<symp> INT DOUBLE BOOLEAN

%type<symp> dec_stmt while_stmt if_head

%type<symp> expression exp statement type factor input_stmt print_stmt assignment_stmt condition_stmt LPAREN RPAREN PRINT

%right ASS
%left  OR
%left  AND
%left  EQ NE
%left  LT LE GT GE
%left  PLUS MINUS
%left  TIMES DEV
%right NOT
%%

Program : statements;

type : INT {strcpy($$.type,$1.type);}
     | DOUBLE {strcpy($$.type,$1.type);}
     | BOOLEAN {strcpy($$.type,$1.type);};

statements : statements statement;
statements : statement;
statement : assignment_stmt;
statement : print_stmt;
statement : input_stmt;
statement : condition_stmt;
statement : while_stmt;

statement : dec_stmt;
dec_stmt : type ID {
            if (findvarINscope($2.name,currentScope)==0 ||strcmp(findtype($2.name,currentScope),$1.type)) {
                insertvar($2.name,$1.type);
            } else
                printf("Line :%d : Variable \"%s\" is already declared in this scope \n", yylineno, $2.name);
    };

assignment_stmt : ID ASS expression 
/*{
                    if(findvarINscope($1.name, currentScope) == 1) { 
                        if(strcmp(findtype($1.name, currentScope), $3.type) != 0)
                            printf("Line :%d : Incompatible type: Assigning %s to %s\n", yylineno, $3.type, findtype($1.name, currentScope));
                    } else {
                        if(findvarINscope($1.name,currentScope)==0)//not found
                            printf("assi Line :%d : Variable \"%s\" is undeclared in this scope \n", yylineno, $1.name);
                    }
    }; */
    
    { if(findvar($1.name,currentScope)==1) // the variable already declared 
    {
       if(strcmp(findtype($1.name,currentScope),$3.type)!=0) // check the type
          printf("Line: %d: Incompatible type: Assigning %s to %s \n",yylineno,$3.type,findtype($1.name,currentScope));
    } else // variable NOT declared
       printf("Line: %d: Variable \"%s\" is undeclared in the scope \n",yylineno,$1.name);
};

expression: exp EQ exp  {
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else 
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);}
       

          | exp NE exp 	{
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);}

          | exp LT exp 	{
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);}

          | exp LE exp 	{
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);}

          | exp GT exp 	{
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else{
        printf("Line :%d : The operand of Relational Operator should have the same type \n", yylineno);
        strcpy($$.type,"");
        }}

          | exp GE exp {
        if ((strcmp($1.type,$3.type) == 0 ))
        strcpy($$.type,"boolean");
        else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);}

        |exp ;
          
exp: exp PLUS exp {
    if((strcmp($1.type, "double") == 0 || strcmp($1.type, "int") == 0) &&
        (strcmp($1.type,$3.type) == 0)){
        strcpy($$.type,$1.type);
        }

    else if((strcmp($1.type, "double") == 0 || strcmp($3.type, "double") == 0) &&
       (strcmp($1.type, "int") == 0 || strcmp($3.type, "int") == 0)){
       strcpy($$.type,"double");
       }
    else {
     printf("Line :%d : Incompatible type: Arthimatic+ operator between %s and %s \n",yylineno,$1.type,$3.type);
    }
}
   | exp MINUS exp {
   if((strcmp($1.type, "double") == 0 || strcmp($1.type, "int") == 0) &&
        (strcmp($1.type,$3.type) == 0)){
        strcpy($$.type,$1.type);
        }

    else if((strcmp($1.type, "double") == 0 || strcmp($3.type, "double") == 0) &&
       (strcmp($1.type, "int") == 0 || strcmp($3.type, "int") == 0)){
       strcpy($$.type,"double");
       }
    else {
     printf("Line :%d : Incompatible type: Arthimatic- operator between %s and %s \n",yylineno,$1.type,$3.type);
    }
   }

   | exp TIMES exp {
   if((strcmp($1.type, "double") == 0 || strcmp($1.type, "int") == 0) &&
        (strcmp($1.type,$3.type) == 0)){
        strcpy($$.type,$1.type);
        }

    else if((strcmp($1.type, "double") == 0 || strcmp($3.type, "double") == 0) &&
       (strcmp($1.type, "int") == 0 || strcmp($3.type, "int") == 0)){
       strcpy($$.type,"double");
       }
    else {
     printf("Line :%d : Incompatible type: Arthimaticx operator between %s and %s \n",yylineno,$1.type,$3.type);
    }
   }
   | exp DEV exp { 
   if ($3.value == 0 || $3.value == 0.0) 
   printf("Line :%d : Division by zero, not allowed \n",yylineno);
   
   else {
   if((strcmp($1.type, "double") == 0 || strcmp($1.type, "int") == 0) &&
        (strcmp($1.type,$3.type) == 0)){
        strcpy($$.type,$1.type);
        }

    else if((strcmp($1.type, "double") == 0 || strcmp($3.type, "double") == 0) &&
       (strcmp($1.type, "int") == 0 || strcmp($3.type, "int") == 0)){
       strcpy($$.type,"double");
       }
    else {
     printf("Line :%d : Incompatible type: Arthimatic/ operator between %s and %s \n",yylineno,$1.type,$3.type);
    }
   }}
   | exp OR exp {
   if(strcmp($1.type,$3.type) == 0){
        if(strcmp($1.type, "boolean") == 0)
        strcpy($$.type,"boolean");
   }else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);
   }
   | exp AND exp {
   if(strcmp($1.type,$3.type) == 0){
        if(strcmp($1.type, "boolean") == 0)
        strcpy($$.type,"boolean");
   }else
        printf("Line :%d : The operand of Relational Operator should have the same type\n", yylineno);
   }
   | NOT exp {
    if(strcmp($2.type, "boolean") == 0)
    strcpy($$.type, $2.type);
    else
        printf("Line :%d : not boolean\n", yylineno);
   }
   | factor
   ;
factor : INT_LITERAL {
    strcpy($$.type ,"int");
    strcpy($$.name,"");
};
factor : DBL_LITERAL {
    strcpy($$.type ,"double");
    strcpy($$.name,"");
};
factor : STRING_LITERAL {
    strcpy($$.type ,"string");
    strcpy($$.name,"");
};
factor : ID {
    if (findvar($1.name,currentScope)==0 && findvarINscope($1.name,currentScope) == 0){ 
    printf("Line :%d : Variable \"%s\" is undeclared in this scope\n",yylineno,$1.name);
    }
    else 
    strcpy($$.type,findtype($1.name,currentScope));
    
};
factor : _TRUE {strcpy($$.type ,"boolean");strcpy($$.name,"");};
factor : _FALSE {strcpy($$.type ,"boolean");strcpy($$.name,"");};

factor : LPAREN exp RPAREN {strcpy($$.type, $2.type); strcpy($$.name,"");};

print_stmt : PRINT LPAREN expression RPAREN;
input_stmt : ID ASS INPUT LPAREN RPAREN ;
//call_stmt : ID LPAREN RPAREN;
//call_stmt : ID LPAREN expr_list RPAREN;

condition_stmt : if_head statements FI {
    currentScope--;
};
condition_stmt : if_head statements ELSE COLON statements FI;

if_head : IF expression COLON  {
        if(strcmp($2.type,"boolean")!=0) 
            printf("Line :%d : In if stmt, the expression should be boolean not %s \n",yylineno,$2.type);
        else
            strcpy($$.type,"boolean");};

while_stmt : WHILE expression COLON  statements ELIHW {
        if(strcmp($2.type,"boolean") != 0)
            printf("Line :%d : In while statement: the type should be boolean not  %s \n",yylineno,$2.type);
        else
            strcpy($$.type,"boolean");};
            
            
%%
int main(int argc, char *argv[])
{
yyin = fopen(argv[1], "r" ) ;
if(!yyparse())
        printf("\nParsing complete\n");
    else
        printf("\nParsing failed\n");
    
    fclose(yyin);

return 0;
}

 int yyerror (char* msg)
{
printf(" %s  in Line : %d %s\n",msg,(yylineno), yytext);
return 0;
}

int findvar(char name[], int scope){
    int i =0;
    for(i=0;i<varcount;i++)
    if(strcmp(symbols[i].name,name) == 0 && symbols[i].scope <= scope )
    return 1; //found
    return 0; //not found
}

int findvarINscope(char name[], int scope){
    int i =0;
    for(i=0;i<varcount;i++)
        if(strcmp(symbols[i].name, name) == 0 && symbols[i].scope == scope )
        return 1; //found
        return 0; //not found
}
void insertvar(char name[], char type[]){
    strcpy(symbols[varcount].name,name);
    strcpy(symbols[varcount].type,type);
    symbols[varcount].scope = currentScope;
    varcount++;
}

char* findtype(char name[], int scope){
    int i =0;
    for(i=varcount-1;i>=0;i--)
    if(strcmp(symbols[i].name,name) == 0 && symbols[i].scope <= scope )
    return symbols[i].type; //found
    return ""; //not found
}
