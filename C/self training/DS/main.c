#include <stdio.h>
#include <stdlib.h>
/*
 * made by: @Deem_Alqud
 */
struct node{
    int data;
    struct node *next;
};
struct LinkedList{
    struct node *head;
};
struct Stack{
    struct node *top;
};
struct Queue{
    struct node *head;
    struct node *tail;
};

//LinkedList
int isEmpty(struct LinkedList *list){
    return list->head == NULL;
}

void insertBeginning(struct LinkedList *list, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

void insertEnd(struct LinkedList *list,int data){
    if (list->head == NULL){
        list->head = (struct node *) malloc(sizeof(struct node));
        list->head->data = data;
        list->head->next = NULL;
        return;
    }
    struct node *current = list->head;
    while (current->next != NULL){//traverse
        current = current->next;
    }
    current->next = (struct node *) malloc(sizeof(struct node));
    current->next->data = data;
    current->next->next = NULL;
}

void insertAfter(struct node *previous, int data){
    if (previous == NULL)
        return;
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = previous->next;
    previous->next = newNode;
}

void insertBefore(struct LinkedList *list, struct node *current, int data){
    if (current == NULL)
        return;
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    if (current == list->head) {
        temp->next = list->head;
        list->head = temp;
        return;
    }
    struct node *previous = list->head;
    while (previous != NULL || previous->next != current) {
        previous = previous->next;
    }
    previous->next =temp;
    temp->next = current;
}

int length(struct LinkedList *list){
    if (isEmpty(list) == 0)
        return 0;
    struct node *temp = list->head;
    int count = 0;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertMiddle(struct LinkedList *list, int data){
    if (list->head == NULL)
        insertBeginning(list, data);
    else{
        struct node *temp = list->head;
        int count =length(list);
        count = count / 2;
        int i;
        for (i = 0; i < count; ++i) {
            temp = temp->next;
        }
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
//void insertSorted(int data){//look it up
//
//}
void concat(struct LinkedList *l1, struct LinkedList *l2){
    if (isEmpty(l2))
        return;
    struct node *temp = l2->head;
    while (temp != NULL){
        insertEnd(l1, temp);
        temp = temp->next;
    }
}

void deleteFromList(struct LinkedList *list, int data) {
    if (list->head == NULL)
        return;
    if (list->head->data == data) {
        struct node *temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }
    struct node *previous = list->head;
    struct node *current = list->head->next;
    while (current != NULL) {
        if (current->data == data) {
            previous->next = current->next;
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void displayList(struct LinkedList *list){
    struct node *temp = list->head;
    while (temp != NULL){
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}
////////////////
////////////////
//Stack
int isEmptyStack(struct Stack *stack){
    return stack->top == NULL;
}

void push(struct Stack *stack, int data){
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack *stack){
    int temp = stack->top->data;
    struct node *tempNode = stack->top;
    stack->top = stack->top->next;
    free(tempNode);//to avoid leaking of data
    return temp;
}

int top(struct Stack *stack){
    return stack->top->data;
}

void displayStack(struct node *current){
    if (current == NULL){
        puts("\nempty stack\n");
        return;
    }
    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    puts("\n");
}
////////////////
////////////////
//Queue

int isEmptyQueue(struct Queue *q) {
    return q->head == NULL;
}

void enqueue(struct Queue *q, int data) {
    if (isEmptyQueue(q)) {
        q->head = (struct node *) malloc(sizeof(struct node));
        q->head->data = data;
        q->head->next = NULL;
        q->tail = q->head;
        return;
    }
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    q->tail->next = newNode;
    //if there is no tail then traverse the whole queue to get to the end
}

int dequeue(struct Queue *q) {
    int temp = q->head->data;
    struct node *tempNode = q->head;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    free(tempNode);
    return temp;
}

void displayQueue(struct Queue *q) {
    if (isEmptyQueue(q)) {
        puts("\nempty queue");
        return;
    }
    struct node *temp = q->head;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}


///////////////
int main() {
    //LL
    struct LinkedList *list = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    insertEnd(list, 1);
    insertBeginning(list, 2);
    insertMiddle(list, 3);
    insertAfter(list->head, 4);
    insertBefore(list, list->head, 5);
    displayList(list);//5 2 4 3 1
    deleteFromList(list, 3);
    deleteFromList(list, 5);
    deleteFromList(list, 1);
    puts("\nafter deleting");
    displayList(list);//2 4
    printf("\nis empty? %s\n", isEmpty(list) == 1 ? "True" : "False");
    puts("\ndeleting the rest");
    deleteFromList(list, 2);
    deleteFromList(list, 4);
    printf("\nis empty? %s\n\n", isEmpty(list) == 1 ? "True" : "False");
    //Stack
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    struct node *first = (struct node *) malloc(sizeof(struct node));
    first->data = 1;
    first->next = NULL;
    push(stack, first->data);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    displayStack(first);
    printf("\ndelete %d\n", pop(stack));
    displayStack(first);
    printf("\nis empty? %s\n", isEmptyStack(stack) == 1 ? "True" : "False");
    return 0;
}
