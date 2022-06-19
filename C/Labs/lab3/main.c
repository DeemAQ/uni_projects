#include <stdio.h>
#include <string.h>
int isPalindrome(char *s);
int main() {
    char str[50];
    printf("enter a word\n");
    scanf("%s", str);
    if (isPalindrome(str) == 0)
        printf("The string is not palindrome\n");
    else
        printf("The string is palindrome\n");
    char *first = str;
    printf("first character in the string is: %c", *first);
    return 0;
}
int isPalindrome(char *s){
    int length = strlen(s);
    char *last = s + (length -1);
    int i = 0;
    for (i; i < length/2; i++) {
        if ((*s++) == (*last--))
            continue;
        else
            return 0;
    }
    return 1;
}