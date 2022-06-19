#include <stdio.h>
#include <stdlib.h>

struct Student{
    char grade;
    char course[7];
    int id;
} Grades[3];

void readInfo();
void printInfo();
int main() {
    FILE *info;
    info = fopen("input.txt", "w");
    if (info == NULL)
        puts("Error opening file");
    else{
        fprintf(info, "%d %s %c\n", 12345, "csc111", 'A');
        fprintf(info, "%d %s %c\n",23456 ,"csc111" ,'B');
        fprintf(info, "%d %s %c\n", 34567 ,"csc111", 'B');
        fclose(info);
        readInfo();
    }
    return 0;
}

void readInfo(){
    FILE *input;
    input = fopen("input.txt", "r");
    if (input == NULL){
        puts("Error while opening the file");
        return;
    }
    int i;
    for ( i = 0; i < 3; ++i) {
        fscanf(input,"%d %s %c\n", &Grades[i].id, Grades[i].course, &Grades[i].grade);
    }
    fclose(input);
    printInfo();
}
void printInfo(){
    int i;
    for (i = 0 ; i <3; i++) {
        printf("%d %s %c ", Grades[i].id, Grades[i].course, Grades[i].grade);
    }
}