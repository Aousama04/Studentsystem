#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Nodelist;

Nodelist * initNodelist();

void insertHead(Nodelist *nodelist, int data);

void insertFail(Nodelist *nodelist, int data);

void showNodelist(Nodelist *nodelist);

void deleteNode(Nodelist *nodelist,int data);

int main(){
    Nodelist *nodelist = initNodelist();
    insertHead(nodelist,1);
    insertHead(nodelist,2);
    insertHead(nodelist,3);
    insertHead(nodelist,3);
    insertHead(nodelist,4);
    insertHead(nodelist,5);
    deleteNode(nodelist,3);
    showNodelist(nodelist);
    return 0;
}


Nodelist * initNodelist(){
    Nodelist *nodelist = (Nodelist *)malloc(sizeof(Nodelist));
    nodelist->data = 0;
    nodelist->next = NULL;
    return nodelist;
}


void insertHead(Nodelist *nodelist, int data) {               //头插
    Nodelist *node = (Nodelist *)malloc(sizeof(Nodelist));
    node->data = data;
    node->next = nodelist->next;
    nodelist->next = node;
    nodelist->data++;
}


void insertFail(Nodelist *nodelist, int data){
    Nodelist *firstNode = nodelist;                                   //尾插
    Nodelist *node = (Nodelist *)malloc(sizeof(Nodelist));
    node->data = data;
    node->next = NULL;
    while (nodelist->next != NULL){              //遍历链表
        nodelist = nodelist-> next;
    }
    nodelist->next = node ;
    firstNode->data++;
}


void showNodelist(Nodelist *nodelist){
    nodelist = nodelist->next;
    while (nodelist){
        printf("%d->",nodelist->data);
        nodelist=nodelist->next;
    }
    printf("NULL\n");
}


void deleteNode(Nodelist *nodelist,int data){            //删除  一次只能删一个
    Nodelist *preNode = nodelist;
    Nodelist *currNode = nodelist->next;
    while (currNode->next != NULL){
        if (currNode->data == data){
            preNode->next = currNode->next;
            free(currNode);


            continue;
        }
        preNode = currNode;
        currNode = currNode->next;
    }
}