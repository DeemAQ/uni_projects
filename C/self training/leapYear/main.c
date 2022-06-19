#include <stdio.h>
//leap year is every 4 years, it has 366 days
int main() {
    int year;
    printf("Enter a year:\n");
    scanf("%d", &year);
    if (year % 400 == 0)
        puts("it is a leap year");
    if ( (year % 4 == 0) && (year % 100 != 0) )
        puts("it is a leap year");
    else
        puts("it is not a leap year");
    return 0;
}
