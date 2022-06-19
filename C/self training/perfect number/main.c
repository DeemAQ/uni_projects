#include <stdio.h>
//a perfect number is when the sum of the divisors (except the number it self) = the number
int isPerfect(int number);

int main() {
    int number;
    printf("Enter a number please:\n");
    scanf("%d", & number);
    int i = isPerfect(number);
    i == 1 ? printf("the number is perfect") : printf("the number is not perfect");
    return 0;
}

int isPerfect(int number) {
    if (number <= 0)
        return 0;
    int i, remainder, sum = 0;
    for (i = 1; i < number; i++) {//number = 5, 1 2 3 4
        remainder = number % i;
        if (remainder == 0)
            sum += i;
    }
    if (sum == number)
        return 1;
    return 0;
}
