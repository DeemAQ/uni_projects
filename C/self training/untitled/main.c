#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

LinkedList* createList(){
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->current = NULL;
    return list;
}

int empty(LinkedList* list){
    return list->head == NULL;
}

int last(LinkedList* list){
    return list->current->next == NULL;
}

int full(LinkedList* list){
    return 0;
}

void findFirst(LinkedList* list){
    list->current = list->head;
}

void findNext(LinkedList* list){
    list->current = list->current->next;
}

void* retrieve(LinkedList* list){
    return list->current->data;
}

void update(LinkedList* list, void* data){
    list->current->data = data;
}

Node* createNode(void* data, Node* next){
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp != NULL)
    {
        temp->data = data;
        temp->next = next;
    }
    return temp;
}

void insert(LinkedList* list, void* data){
    if (list->head == NULL)
    {
        list->head = createNode(data, NULL);
        list->current = list->head;
    } else{
        Node* temp = list->current->next;
        list->current->next = createNode(data, temp);
        list->current = list->current->next;
    }
}

void removeC(LinkedList* list){
    Node* q, *p;
    if (list->current == list->head)//one node
    {
        q = list->head;
        list->head = list->head->next;//which is NULL
    } else{
        p = list->head;
        while (p->next != list->current)
            p = p->next;
        q = list->current;
        p->next = list->current->next;
    }
    if (list->current->next == NULL)
    {
        list->current = list->head;
    } else{
        list->current = list->current->next;
    }
    free(q);
}

void removeList(LinkedList* list){
    Node* temp;
    while (list->head != NULL){
        temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
    free(list);
}
int length(LinkedList *list) {
    int count = 0;
    if (empty(list) == 0) {
        findFirst(list);
        while (last(list) == 0) {
            count++;
            findNext(list);
        }
        count++;
    }
    return count;
}

void printList(LinkedList *list) {
    int *p;
    findFirst(list);
    while (last(list) != 1) {
        p = retrieve(list);
        printf("%d\t", *p);
        findNext(list);
    }
    p = retrieve(list);
    printf("%d\n", *p);
}

int main(void) {
    int *p;
    LinkedList *l = createList();
    p = (int *) malloc(sizeof(int));
    *p = 45;
    insert(l, p);
    p = (int *) malloc(sizeof(int));
    *p = 55;
    insert(l, p);
    p = (int *) malloc(sizeof(int));
    *p = 88;
    insert(l, p);
    p = (int *) malloc(sizeof(int));
    *p = 77;
    insert(l, p);
    p = (int *) malloc(sizeof(int));
    *p = 3;
    insert(l, p);
    p = (int *) malloc(sizeof(int));
    *p = 99;
    insert(l, p);
    printList(l);
    removeC(l);
    printList(l);
    removeList(l);
    return 0;
}