#include <stdio.h>
void letterCase(char *c){
    int i = 0;
    while (c[i] != '\0'){
        i++;
    }
    c[0] -= 32;
    c[i - 1] -= 32;
    printf("%s", c);

}
void isEven(int a){
    if (a % 2 != 0){
        printf("the number entered %d is odd", a);
        return;
    }
    printf("even numbers between 1 and %d\n", a);
    int i = 2;
    while (i <= a) {
        //if (i % 2 == 0)
        printf("%d ", i);
        i += 2;
    }

}
int main() {
    printf("Enter a word:\n");
    char word[50];
    scanf("%s", word);
    letterCase(word);
    printf("\n\n");
    printf("enter an even number:\n");
    int num;
    scanf("%d", &num);
    isEven(num);
    return 0;
}
