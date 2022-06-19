#include <stdio.h>

int main() {
    int rows, n = 1;
    printf("enter the number of rows:\n");
    scanf("%d", &rows);
    int i, j;
    for (i = 1; i <= rows; i++){
        for (j = 1; j <= i; j++){
            printf("%d ", n++);
        }
        printf("\n");
    }
    return 0;
}
