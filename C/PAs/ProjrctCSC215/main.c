#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Taxi {
    int id;
    char name[20];
    char category[20];//standard, business, family
    char plate[7];//3 characters 3 digits
    char color[20];
    float rate;
    float minCharge;
    char state;//A or R
    struct Taxi *next;
};
struct Taxi* list;

void addTripCar() {
    //add from the text file
    struct Taxi *current, *head = NULL, *tmp;
    FILE *file = fopen("Taxies.txt", "r");
    if (!file) {
        perror("Error while opening the file");
        exit(1);
    }

    //int i;
    char *header = (char *) malloc(sizeof(char )*100);

    //to count the number of lines
//    int numberOfLines = 0;
//    char c;
//    for (c = getc(file); c != EOF; c = getc(file)) {
//        if (c == '\n')
//            numberOfLines++;
//    }

    //rewind(file);//did not work!
    //fclose( file );
   // FILE *file1 = fopen("Taxies.txt", "r");

    //getline(header, (size_t *) sizeof(char *), file);//to read the header of the columns
    //fgets(header,100, file1);
    fscanf(file, "%[^\n]", header);
   // for (i = 0; i < numberOfLines - 1 ; i++) {
   tmp = (struct Taxi *) malloc(sizeof(struct Taxi));//7 is the number of columns
   while (fscanf(file,"%d %s  %s %s %*s %f %f ", &(tmp->id) ,
                 tmp->name , tmp->category , tmp->plate, &(tmp->rate) , &(tmp->minCharge) ) != EOF){

        //change the state
        tmp->state = 'A';

        if (!head) {//empty list
            head = current = tmp;
        } else {//if the list is not empty
            current->next = tmp;
            current = current->next;
        }
       tmp = (struct Taxi *) malloc(sizeof(struct Taxi));
    }

    current->next = NULL;//next is null
    fclose(file);
    list = head;
}

void setTripCar(char *category, float rate) {
    struct Taxi* tmp = list;
    while (tmp) {
        if (strcmp(tmp->category, category) && tmp->rate == rate) {//changes every equivalent category and rate
            tmp->state = 'R';
        }
        tmp = tmp->next;
    }
}

void writeCarsInRide(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (!file) {
        perror("Error while opening the file");
        return;
    }
    fseek(file, 1, SEEK_END);//to point to the end of the file
    struct Taxi* tmp = list;
    fprintf(file, "\nThe trip cars:\nid\t\tdriver\t\tcategory\t\tplate\t\trate\t\tstate\n");
    while (tmp) {
        fprintf(file, "%-10d %-10s %-14s %-12s %-10.1f %-7c\n", tmp->id, tmp->name, tmp->category, tmp->plate,
                tmp->rate, tmp->state);
        tmp = tmp->next;
    }
    fclose(file);
}

void printList() {
    struct Taxi* tmp = list;
    while (tmp) {
        printf("%-20d %-20s %-20s %-20s %-20.1f %-20.1f %-20c\n", tmp->id, tmp->name, tmp->category, tmp->plate,
               tmp->rate, tmp->minCharge, tmp->state);
        tmp = tmp->next;
    }
}

int main() {
    addTripCar();
    printList();

    setTripCar("Business", 4.5);
    setTripCar("Family", 5.0);
    setTripCar("Family", 4.0);
    setTripCar("standard", 3.4);
    setTripCar("standard", 5.0);
    printf("----------------------------------------------------------------"
           "----------------------------------------------------------------\n");
    writeCarsInRide("Taxies.txt");

    printList();

    return 0;
}
