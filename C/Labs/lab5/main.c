#include <stdio.h>
#include <stdlib.h>
void more_Grades(float *Grades, int num, int sizeOfGrades);
int main() {
float *Grades;
printf("How many grades do you want to store:\n");
int numOfInput;
scanf("%d", &numOfInput);
Grades = (float *) calloc(numOfInput, sizeof(float ));
int i;
float g;
for (i = 0; i < numOfInput; i++){
    printf("Enter grade %d :\n", i+1);
    scanf("%f", &g);
    *(Grades + i) = g;
}
more_Grades(Grades, numOfInput, (i - 1)*sizeof(float));
    return 0;
}
void more_Grades(float *Grades, int num, int sizeOfGrades){
    float input;
    int counter = num;
    puts("to add more student's grades:\n");
    do {
        printf("Enter grade %d :\n", ++counter);
        float *more = (float *) realloc(Grades, counter*sizeof(float));
        scanf("%f", &input);
        if (more != NULL){
            Grades = more;
            if (input >= 0)
            *(Grades + (counter - 1)) = input;
            else
                break;
        }else{
            free(Grades);
            puts("Error");
            return;
        }

    }while (input >= 0);

    printf("number of student's grade in the dynamic grade lis: %d\n", counter-1);
    int i;
    printf("grades: ");
    for (i = 0; i < counter-1; i++) {
        printf("%.2f ", *(Grades + i));
    }
    //sizeof(float) = 4
    printf("\nsize of the dynamic grade list: %d bytes", (counter - 1)*sizeof(float));
    free(Grades);
}