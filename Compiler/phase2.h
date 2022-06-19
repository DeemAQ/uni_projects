// this is an example, you can add any fields or remove fields depends on your structure for the symbol table
struct symbols{
char name[30];
char type[30];
int value;
int scope;
};

// add your table structure here (array , stack etc )
struct symbols symbols[50];
// basic function on symbol table  you can add more
int findvar(char name[], int scope);
int findvarINscope(char name[], int scope);
void insertvar(char name[], char type[]);
char* findtype(char name[], int scope);
