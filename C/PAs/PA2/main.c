#include <stdio.h>
#include <string.h>
struct Employee{
   int id;
   char name[20];
   int salary;
   char childrenNames[5][20];
   int counter;
};
void printChildren(struct Employee *array, int id);
int main() {
    int i, j;
    char name[20];
    struct Employee *employee;
    for (i = 1; i <= 3; ++i) {
        printf("Enter employee #%d: ", i);
        scanf("%d", &employee -> id);
        printf("\nEnter employee name: ");
        getchar();
        gets(name);
        strcpy(employee -> name, name);//could've used scanf or gets directly,,, but i followed the slides
        printf("\nEnter employee salary: ");
        scanf("%d", &employee -> salary);
        printf("\nHow many kids? ");
        scanf("%d", &employee -> counter);
        while (employee -> counter < 0 || employee -> counter > 5){//without this while loop the program will end up in an infinite loop because of pointers
            printf("please enter a valid value, between 0 and 5: ");
            scanf("%d", &employee -> counter);
        }
        for (j = 0; j < employee -> counter; j++){
            printf("\nEnter child #%d name: ", j+1);
            scanf(" %s", name);
            strcpy(employee -> childrenNames[j], name);
        }
        employee++;
        printf("\n");
    }
    printf("\nEnter the id of the employee you would like to view his child's"
           "name starting with the letter S: ");
    int idOfS;
    scanf("%d", &idOfS);
    printChildren(employee - 3, idOfS);
    return 0;
}
void printChildren(struct Employee *array, int id){
    int i, j, found = 0;
    for (i = 0; i < 3; i++) {
        if (array->id == id) {
            found = 1;
            if (array->counter == 0) {
                puts("This employee has no children");
                return;
            } else
                break;
        }
        array++;
    }
    if (found == 1){
        for (j = 0; j < array->counter; ++j)
            if (array->childrenNames[j][0] == 's' || array->childrenNames[j][0] == 'S')
                printf("%s %s\n", array->childrenNames[j], array->name);
    } else
    puts("This employee doesn't exist");
}