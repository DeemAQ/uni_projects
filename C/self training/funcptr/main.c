#include <stdio.h>
int mul(int a, int b, int c) {
    return a * b * c;
}
void A(){
    printf("Hello World!");
}

typedef enum deem f;

void B(void (*ptr)()){
    ptr();
}
void first(){
    printf("Deem is the GOAT\n");
}
void add(int a, int b){
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b){
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b){
    printf("Multiplication is %d\n", a*b);
}
void func(int a, void (*funcPtr)(int, int)){
    funcPtr(a, a);
}
//int main(){
//    typedef void(*subFunction) (int, int);
//    subFunction sub = multiply;
//    typedef void (*Function) (int, void (*ptr) (int, int));
//    Function function;
//    function = func;
//    function(2, sub);
//    void (*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
//    int c = 2, a = 15, b = 10;
//    fun_ptr_arr[c](a, b);//multiply
//}

int fun(int array[]){
    int s = sizeof(array);
    int m = sizeof(void *);
    int t =  sizeof(int);
    return array[6];
}
void (*ptr[3])();
void a() {
    printf("hi ");
}
void b(){
    (*ptr)();
    printf("hello ");
}
void c(){
    ptr[3] = ptr[1];
    printf("bye ");
    ptr[3]();
}
int main(){
    ptr[0]=a;
    ptr[1]=&b;
    ptr[2]=c;
    ptr[2]();
}



//int main() {
//    typedef void (*Function)();
//    Function function;
//    function = first;
//B(function);
//    typedef int(*Function) (int, int, int);
//    Function function;
//    function = mul;
//    int x = function(3, 4, 1);
//    printf("%d\n", x);
//    int (*function_pointer)(int, int, int);
//    function_pointer = mul;
//    printf("The product of three numbers is: %d", function_pointer(2, 3, 4));
//void function(char**);
////int main(){
////    char *Months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun" };
////    function(Months);
////    return 0;
////}
////void function(char **ptr)
////{
////    char *ptr1;
////    char **temp = ptr += sizeof(int);
////    ptr1 = (temp)[-2];
////    printf("%s\n", ptr1);
//}
//
//int main(){
//    struct node	{
//        int a, b, c;
//        struct	node *next;
//    };
//    struct node num = {3, 5, 6};
//    struct node *ptr = & num;
//    int *x = ((int*)ptr + 1 + (3-2));
//    printf("%d\n", *x);
//}
