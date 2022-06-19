#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
int* countInteger(char* str);
char* lastWord(char* str);
void replace (char* str);
int main(int argc, char const *argv[])
{
    char sentence[SIZE];
    printf("Enter a sentence please:\n");
    //scanf("%[^\n]", sentence);
    gets(sentence);
    printf("\nThe number of numerical characters in the sentence =%d\n", *countInteger(sentence));
    printf("The last word in the sentence :%s\n", lastWord(sentence));
    replace(sentence);
    printf("The sentence after replacing the white spaces with dashes:%s\n", sentence);
    return 0;
}
int* countInteger(char* str){//The function counts and returns the number of numeric characters in the received string
    int length = strlen(str);
    int counter = 0;
    int i;
    for ( i = 0; i < length; i++) {
        char c = *str++;
        if ( ('0' <= c) && (c <= '9') )
            counter++;
    }
    int *cp = &counter;//tried to cast to a pointer here but failed due to a warning, so instead i created an int* pointer
    return cp;
}

char* lastWord(char* str){//The function extracts and returns the last word from the received string
    char *p= strrchr(str, ' ');
    if (p != NULL)//if false it means that str is one word only
        return ++p;//pre increment because of the way strrchr() substrings
    return str;
}
void replace(char* str){//The function replaces all occurrence of white spaces in the received string with dash character ‘-‘. The replacement should be on the *original string*.
    //original string so don't use a pointer
    int i =0, length = strlen(str);
    while (i < length){
        if (*(str + i) == ' '){
            *(str + i) = '-' ;//150 is ASCII for dash –
        }
        i++;
    }
}