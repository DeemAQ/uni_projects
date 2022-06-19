//
// Created by Deem on 12/10/2020.
//

#ifndef UNTITLED_LL_H
#define UNTITLED_LL_H
#include<stdio.h>
#include<stdlib.h>

struct node {
    void* data;
    struct node* next;
};
typedef struct node Node;

struct LinkedList {
    Node* head;
    Node* current;
};
typedef struct LinkedList LinkedList;

//functions
LinkedList* createList();
int empty(LinkedList *);
int last(LinkedList *);
void findFirst(LinkedList *);
void findNext(LinkedList *);
void* retrieve(LinkedList *);
void update(LinkedList *, void*);
Node* createNode(void*, Node*);
void insert(LinkedList *, void*);
void removeC(LinkedList *);
#endif //UNTITLED_LL_H
