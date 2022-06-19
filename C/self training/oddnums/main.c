#include <stdio.h>
struct record
{
    int x,y;
};
struct record rec;
int main() {
    int i;
    /* create the file of 10 records */
    FILE *f=fopen("rec.txt","w");
    if (!f)
        return 1;
    for (i=1;i<=10; i++) {
        rec.x=i;
        fwrite(&rec, sizeof( rec),1,f);
    }
    fclose(f);
    FILE *fp=fopen("rec.txt","r");
    if (!fp)
        return 1;
    int offset = 0;
    fseek(fp,offset,SEEK_SET);
    while (fread(&rec,sizeof(rec),1,fp)){//printing only odd numbers
        if (rec.x % 2 == 1)
            printf("%d\t%d\n",rec.x, rec.y);
        fseek(fp, sizeof(rec),SEEK_CUR);
    }
    fclose(fp);

    return 0;
}
