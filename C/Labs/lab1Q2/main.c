#include <stdio.h>

int main() {
    int number;
    printf("enter an integer: ");
    scanf("%d", &number);
    number == 0 ? printf("then integer is 0 number") :
    number % 2 == 0 ? printf("the number %d is even", number) : printf("the number %d is odd", number);
    return 0;
}
