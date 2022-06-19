//Deem Alqudaimi 439201062

typedef struct {
    char fullName[100];
    int accNum;
    char accType[15];
} customer;
int writeCustomer (customer* cList);
customer* loadCustomer( char* filename, int num);
int updateCustomer( char* filename );
void print_customer (customer* c );
customer enter_customerInfo();
