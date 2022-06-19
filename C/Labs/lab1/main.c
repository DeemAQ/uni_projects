#include <stdio.h>

int main() {
    double const price;
    printf("enter the old price: ");
    scanf("%lf", &price);
    double priceAfterDiscount = price - (price * 0.25);
    printf("price of book after sale 25%% = %-10.3fSR", priceAfterDiscount);
    return 0;
}
