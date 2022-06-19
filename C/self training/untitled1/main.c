#include<stdio.h>
#include<pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

//int n,i;
//int arr[20]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
//int sum=0;
//int counter = 0;
////int n = 20;
//int n=sizeof(arr)/sizeof(arr[0]);
//void*th(){
//    float average;int total=0;
//    for(i=0;i<n;i++){
//        total=total+arr[i];
//    }average=(float)total/n;
//    printf("\nThe average value is = %f \n",average);
//    counter++;
//}
//void*th1(){
//    int max=arr[0];
//    for(int i=1;i<n;i++){
//        if(max<arr[i]){
//            max=arr[i];
//        }
//    }
//    printf("\nThe Maximum  value is = %d \n",max);
//    counter++;
//}
//void*th2(){
//    for(i=0;i<n;i++){
//        sum=sum+arr[i];
//    }
//    printf("\nThe Summation value is = %d \n",sum);
//    counter++;
//}
//int main(){
//    pthread_t t1;
//    pthread_t t2;
//    pthread_t t3;
//    pthread_create(&t1,NULL,&th,NULL);
//    pthread_join(t1,NULL);
//    printf("\n done and my value is %d\n",n);
//    pthread_create(&t2,NULL,&th1,NULL);
//    pthread_join(t2,NULL);
//    printf("\n done and my value is %d\n",n);
//    pthread_create(&t3,NULL,&th2,NULL);pthread_join(t3,NULL);
//    printf("\n done and my value is %d\n",n);
//    printf("\n\nnumber of process = %d", counter);
//     return 0;
//}
//int value = 5;
//int main(){
//    pid_t pid = fork();
//    if (pid == 0){
//        value += 5;
//        printf("value = %d in process = %d\n", value, getpid());
//        exit(0);
//    } else{
//        wait(NULL);
//        pid = fork();
//        if (pid == 0)
//            value += 10;
//    }
//    value++;
//    printf("value = %d in process = %d\n", value, getpid());
//    return 0;
//}
//int main(){
//    int i;
//    pid_t pid;
//    printf("original %d\n", getpid());
//    for (int j = 0; j < 3; ++j) {
//        pid = fork();
//        if (pid == 0)
//            printf("child = %d in %d\n", getpid(), j);
//    }
//}

int main(){
    pid_t pid = fork();
    int n = 5;
    if (pid == 0){
        printf("A: %d\n", getppid());
        execlp("date", "date", NULL);
        n *= 6;
    } else{
        wait(NULL);
        n *= 2;
        printf("B: %d\n", getpid());
    }
    printf("C: %d\n", getpid());
    printf("D: %d\n", n);
    return 0;
}