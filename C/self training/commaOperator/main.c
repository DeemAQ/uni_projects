#include <stdio.h>

int main() {
    int a = 50;
    int b = (a++, ++a);
    printf("%d ", b);//52
    return 0;
}
