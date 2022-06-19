#include <stdio.h>
#include <stdlib.h>
struct Student{
    int roll;
    char name[25];
    float marks;
};
struct record
{
    int x,y;
};
struct record rec;

int main() {
    //Example 1: number of vowels
    /*
    FILE *fp; char ch; long pos; int totalVowels = 0;
    fp = fopen("file.txt","r"); //Statement 1
    if(fp == NULL){
        printf("\nCan't open file or file doesn't exist.");
        exit(0);
    }
    printf("\nData in file...\n");
    while((ch = fgetc(fp))!=EOF) { //Statement 2
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U'){
            pos=ftell(fp); //Statement 3
            totalVowels++;
            printf("\nPosition of %c is at %ld",ch,pos);
        }
    }
    fclose(fp);
    printf("\ntotal number of vowels = %d", totalVowels);*/

    //Example 2: using fseek
    /*FILE *fp; char ch; int offset;
    struct Student Stu;
    fp = fopen("student.txt","r");//Statement1 for reading all
    if(fp == NULL){
        printf("\nCan't open file or file doesn't exist.");
        exit(0);
    }
    printf("\n\nLast record in file.\n");
    offset = sizeof(Stu) * -1; // statement A
    fseek(fp,offset,SEEK_END); // statement B
    //offset is negative so it would go back to the left (SEEK_END makes the file go to EOF)
    fread(&Stu,sizeof(Stu),1,fp); // statement C
    //1 so it would read one record
    printf("\n\tRoll : %d",Stu.roll);
    printf("\n\tName : %s",Stu.name);
    printf("\n\tMarks : %f",Stu.marks);
    printf("\n\nFirst record in file.\n");
    fseek(fp,0,SEEK_SET); // statement D
    fread(&Stu,sizeof(Stu),1,fp);
    printf("\n\tRoll : %d",Stu.roll);
    printf("\n\tName : %s",Stu.name);
    printf("\n\tMarks : %f",Stu.marks);
    printf("\n\nSecond record in file.\n");
    fseek(fp,0,SEEK_CUR); // // statement E
    fread(&Stu,sizeof(Stu),1,fp);
    printf("\n\tRoll : %d",Stu.roll);
    printf("\n\tName : %s",Stu.name);
    printf("\n\tMarks : %f",Stu.marks);
    fclose(fp);*/

    //Example 3: writing then reading from a file
   /* FILE *fp = fopen("records.txt", "w");
    if (!fp)
        exit(1);
    int i;
    for (i = 1; i <= 10; i++) {
        rec.x = i;
        rec.y = 0;
        fprintf(fp, "%d %d\n", rec.x, rec.y);
    }
    fclose(fp);
    FILE *fp2 = fopen("records.txt", "r");
    if (!fp2)
        exit(1);
    fseek(fp2, 0, SEEK_SET);
    for (i=0;i<5; i++){
        fread(&rec, sizeof(rec),1, fp2);
        printf("%d\t%d\n",rec.x, rec.y);
        fseek(fp2, sizeof(rec), SEEK_CUR);
    }
    fclose(fp2);
    FILE *f=fopen("records.txt","r+");
    if (!f)
        return 1;
    fseek(f,sizeof(struct record)*3,SEEK_SET);
    fread(&rec,sizeof(struct record),1,f);
    rec.x=100;
    rec.y = 100;
    fseek(f,sizeof(struct record)*3,SEEK_SET);
    fwrite(&rec,sizeof(struct record),1,f);
    fclose(f);

//for (;;){
//    char c;
//    if ((c = getc(fp2)) == EOF)
//        break;
//    ungetc(c, fp2);
//    fread(&rec, sizeof(rec), 1, fp2);
//    if (rec.x % 2 == 1)
//        printf("%c %c\n", rec.x, rec.y);*/
    /*const char * str;
    str = "Hello world!"; // Line A
    printf( "%d", puts(str)); // Line B
   // str[0] = "h"; // Line C
*/
    /*char str[20];
    printf("Enter the string? "); // suppose the input is “Hello CSC215”
    fgets(str, 10, stdin);
    printf("%s", str);*/
   /* char str[10];
    printf("Enter a string : "); // suppose the input is “Hello CSC215”
    gets(str);
    printf("You entered: %s", str);*/
    /*ungetc('\n',stdin);
    ungetc('m',stdin);
    ungetc('a',stdin);
    ungetc('r',stdin);
    ungetc('g',stdin);
    ungetc('o',stdin);
    ungetc('r',stdin);
    ungetc('P',stdin);
    while(putchar(getchar()) != '\n') ;*/
    /*FILE* ptr = fopen("abc.txt","r");
    if (ptr==NULL) {
        printf("no such file.");
        return 0; }
    char* buf[100];
    while (fscanf(ptr,"%*s %*s %s ",buf)==1) // statement A
        printf("%s\n", buf);*/
    FILE* ptr = fopen("abc.txt","r");
    if (ptr==NULL) {
        printf("no such file.");
        return 0;
    }
    int num;
    char* s [100];
    if (fscanf(ptr,"%*s %s %*s" , s) == 1)// read the headers
        printf("%s\n",s);
    while (fscanf(ptr,"%*s %d %*s",&num) == 1)//read only integers
        printf("%d\n",num);

    return 0;
}

