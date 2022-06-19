#include <stdio.h>
#include <stdlib.h>

void NumOfCharacter (FILE*, FILE*, char ch , char *line);

int main() {
    FILE *fpi, *fpo;
    fpi = fopen("input.txt", "r"); // Open a file to read from
    fpo = fopen("output.txt", "w"); // Open a file to write to
    if (fpi == NULL || fpo == NULL)
        printf("Error opening file\n"); // There was an error in opening either file
    else {

        char c ;
        printf("Enter char ");
        scanf("%c" , &c );
        char line[80] ;

        NumOfCharacter (fpi, fpo , c , line ); //


        fclose(fpi);
        fclose(fpo); // Close the files when done
    }

    return 0; }

void NumOfCharacter (FILE* fpi, FILE* fpo, char ch , char *line) {

    int num = 0;
    int i = 0;
    int total = 0;

    while (fgets(line, 80, fpi) != NULL) {
        num = 0;
        i++;
        while (*line != '\0') {
            if (*line == ch) num++;
            line++;
        }
        total += num;
        if (num != 0)
            fprintf(fpo, "Line#: %d, Frequency of %c = %d \n", i, ch, num);
    }

    fprintf(fpo, "Total frequency of %c = %d \n", ch, total);

}