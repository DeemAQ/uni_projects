#include <stdio.h>
//convert binary to decimal
int main() {
    printf("Enter a number in binary\n");
    int decimal = 0, number, weight = 1, remainder = 0;
    scanf("%d", &number);
    while (number != 0){ //number = 1001
        remainder = number % 10;//to get the last digit
        decimal += remainder * weight;
        number = number / 10;//to delete the last digit
        weight *= 2;//to increase weight
    }
    printf("%d\n", decimal);
    return 0;
}
