#include <stdio.h>
#include <string.h>
union StudentGrade{
    char charGrade;
    int intGrade;
};


struct Student {
    char ID[4];
    union StudentGrade grade;
};


int main() {
char id[4];
char choice;
double average = 0;
double numberOfStudents = 0;
int numOfAs = 0;
double numOfFs = 0;
struct Student student;
    do {
        puts("Enter ID: ");
        scanf(" %s", id);
        if (strcmp(id , "0000") == 0)
            break;
        strcpy(student.ID, id);
        puts("0 for char grade 1 for int grade\n");
        scanf(" %c", &choice);
        switch (choice) {
            case '0':
                puts("Enter a char grade: ");
                scanf(" %c", &student.grade.charGrade);
                if (student.grade.charGrade == 'a' || student.grade.charGrade == 'A')
                    numOfAs++;
                if (student.grade.charGrade == 'f' || student.grade.charGrade == 'F')
                    numOfFs++;
                break;
            case '1':
                puts("Enter an int grade: ");
                scanf("%d", &student.grade.intGrade);
                if (student.grade.intGrade >= 90)
                    numOfAs++;
                if (student.grade.intGrade <= 60)
                    numOfFs++;
                break;
            default:
                puts("Error");
        }
        numberOfStudents++;
    }while (strcmp(id, "0000") != 0);

printf("number of students who took grade 'A' is = %d \n", numOfAs);
if(numberOfStudents != 0) {
    average =  numOfFs / numberOfStudents;
}
printf("Average number Student who take grade 'F' is = %.3f", average);




    return 0;
}
