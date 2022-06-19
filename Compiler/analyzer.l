%{
#include <stdio.h>

int lc=0;
int intc=0;
int dc=0;

char* header_list[100]={"Method headers:\n"};
int headerc=1;

char* call_list[100]={"Method calls:\n"};
int callc=1;

char* var_list[100]={"Variables:\n"};
int varc=1;

char* str;
%}


/* regular definitions */
delim [ \t\n]
ws {delim}+
letter [A-Z a-z]
digit [0-9]
type (double|int|char|signed|float|shorts|svoid)
keyword {type}|main|auto|struct|break|else|long|switch|case|enum|register|typedef|extern|return|union|continue|for|void|do|if|static|while|default|goto|sizeof|volatile|const


identifier [A-Z]({letter}|{digit}|_)*
integer [-+]?{digit}+
double {integer}"."{digit}+
variable ({letter}|_)({letter}|{digit}|_)*
funcHeader {type}[ ]{variable}[ ]*
stringToken ["]([^\"]|[\n])*[\"]
stringWithLine ({stringToken}[\n])*
ignoreThis \'[^'']*\'
line \n
beginning \/\*
end \*\/
dot .


/* REs: */
%%

{line} {lc++;}

{stringToken} ;

stringWithLine {lc++;}

{ignoreThis} ;

\/\/.*\n {lc++;}

{beginning}[^*/]*{end} {lc++;}

{type}[ ]{identifier}/[^\(] {
	asprintf(&str, "%s in line %d", yytext, lc);
	var_list[varc++]=str;
	}

{integer} {intc++;}

{double} {dc++;}

{funcHeader}/[\(] {
	asprintf(&str, "%s in line %d", yytext, lc);
	header_list[headerc++]=str;
	}

{variable}/[\(] {
	asprintf(&str, "%s in line %d", yytext, lc);
	call_list[callc++]=str;
	}	

{dot} ;
%%


int main(int argc, char **argv) {
yyin = fopen("t.c", "r");
yylex();

int i=0;
int j=0;
int k=0;

for(i;i<headerc;i++){
	printf("%s\n",header_list[i]);
}
printf("\n");


for(j;j<callc;j++){
	printf("%s\n",call_list[j]);
}
printf("\n");


for(k;k<varc;k++){
	printf("%s\n",var_list[k]);
}
printf("\n");


printf("The number of integer numbers is %d\n",intc);
printf("The number of double numbers is %d\n",dc);

return 0;
}