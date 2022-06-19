//Deem Alqudaimi 439201062

#include "Customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int writeCustomer(customer* cList){
    FILE* input;
    input = fopen("info.dat", "w");
    if (input == NULL) {
        return errno;
    }
    int i;
    for (i = 0; i < 2; i++) {
        if (fwrite(cList, sizeof(customer), 1, input)){
            cList++;
        } else {
            fclose(input);
            return -1;
        }
    }
    fclose(input);
    return 0;
}

customer* loadCustomer(char* fileName, int num){
    FILE* file;
    customer* cList = (customer*) calloc(num, sizeof(customer));
    file = fopen(fileName, "r");
    if (file == NULL)
        return NULL;
    int x = fread(cList, sizeof(customer), num, file);
    if (x != num) {
        perror("ERROR:");
        fclose(file);
        return NULL;
    }
    fclose(file);
    return cList;
}

int updateCustomer(char* fileName){
    FILE* file;
    file = fopen(fileName, "r+");
    if (file == NULL)
        return errno;
    //first locate the last customer in the file
    //from the end of the file go to the offset(size of customer) going backwards means negative offset
    fseek(file, sizeof(customer) * -1, SEEK_END);
    customer c;
    //call enter customer info so that the info will get updated
    c = enter_customerInfo();
    if (fwrite(&c, sizeof(customer), 1, file)) {//another way to write into a file
        fclose(file);
        return 0;
    }
    fclose(file);
    return -1;
}

void print_customer(customer* c){
   printf("customer's Name: %s\ncustomer's Account#: %d\ncustomer's Account type: %s\n",
      c->fullName, c->accNum, c->accType);
}

customer enter_customerInfo(){
    customer c;
    printf("\nEnter customer's fullname:\n");
    fgets(c.fullName, 100, stdin);//fgets so it won't exceed 100 characters
    printf("Enter customer's account#:\n");
    scanf("%d", &c.accNum);
    getchar();
    printf("Enter customer's account type:\n");
    fgets(c.accType, 15, stdin);//fgets so it won't exceed 15 characters
    return c;
}