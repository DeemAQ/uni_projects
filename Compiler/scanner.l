%{
#include<stdio.h>
%}

beginning \/\*
end \*\/

/* REs: */
%%

[\t ]+ fprintf(yyout, " ");		
.|\n fprintf(yyout, "%s", yytext);	

\/\/.*\n ;
{beginning}[^*/]*{end} ;

%%


int main(int argc, char **argv) {
/*yyin = fopen(argv[1], "r");*/	
yyin = fopen("test.c", "r");
yyout = fopen("out.c", "w");
yylex();
return 0;
}
