#include <stdio.h>
//print the Fibonacci series
int main() {
    printf("enter a number\n");
    int number;
    scanf("%d", &number);
    int first = 0, second = 1, i, sum = 0;
    for (i = 0; i < number; i++){
        printf("%d ", first);
        sum = first + second;
        second = first;
        first = sum;
    }
    return 0;
}
