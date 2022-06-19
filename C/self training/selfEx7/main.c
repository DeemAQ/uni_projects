//#include<stdio.h>
//#include<stdlib.h>
//int main(){
//    int *numbers = (int*)calloc(4, sizeof(int));
//    numbers[0] = 9;
//    free(numbers);
//    printf("%d ", numbers[0]);
//    return 0;
//}
// # include<stdio.h>
// # include<stdlib.h>
// void fun(int *a)
// {
//  a = (int*)malloc(sizeof(int));
// }
// int main()
// {
//  int *p;
//  fun(p);
//  *p = 6;
//  printf("%d",*p);
//  return(0);
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// int *j = (int*)malloc(4 * sizeof(int));
// *j = 9;
// free(j);
// printf("%d", *j);
// return 0;
// }
// #include<stdio.h>
// #include<stdlib.h>
// int main()
// {
// int *p;
// p = (int *)malloc(20);
// printf("%d\n", sizeof(p));
// free(p);
// return 0;
// }
//
//#include<stdio.h>
//int main()
//{
//    int *p = (int *)malloc(sizeof(int));
//    p = NULL;
//    free(p);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int main(){
//    int n, m, i;
//    puts("how many names do you want to store?");
//    scanf("%d", &n);
//    char **names = (char **) calloc(n, sizeof(char *));
//    for (i = 0; i < n; i++){
//        char name[100];
//        puts("enter the name:");
//        scanf(" %s", name);
//        m = strlen(name);
//        names[i] = calloc(m, sizeof(char));
//        strcpy(names[i], name);
//    }
//    puts("_________________________________________________");
//    for (i = 0; i < n; i++){
//        puts(names[i]);
//    }
//}
#include<stdio.h>
#include<stdlib.h>
void populate(int*a){
    int*parr = (int*)malloc(2*sizeof(int));
    parr[0] = 37;
    parr[1] = 73;
    *a = *parr;
}
int main(){
    int *a = NULL;
    populate(a);
    printf("a[0] = %d and a[1] = %d\n", a[0], a[1]);
    return 0;
}

