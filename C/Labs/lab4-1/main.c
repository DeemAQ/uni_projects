#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* strConcat (char* s1, char* str2);
int main() {
    printf("enter name1: ");
    char s1[100], s2[100];
    gets(s1);
    printf("\nenter name2: ");
    gets(s2);
    printf("\nconcatenated: %s", strConcat(s1, s2));
    return 0;
}
char* strConcat (char* s1, char* str2){// contacts 2 strings and returns the pointer of new concatenated string
    int sizeS1 = strlen(s1), sizeS2 = strlen(str2);
    int i;
    char *concat = malloc((sizeS1 + sizeS2) * sizeof(char));
    for (i = 0; i < sizeS1; i++) {
        *(concat + i) = *(s1 + i);
    }
    int j;
    for (i = sizeS1,  j = 0; i < (sizeS2 + sizeS1); i++) {
        *(concat + i) = *(str2 + j);
        j++;
    }
    return concat;
}