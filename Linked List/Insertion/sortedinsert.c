#include <stdio.h>
#include <stdlib.h>

//Define Structure for a Node

struct Node {

    int data;
    struct Node *next;

}*first=NULL;           //global variable


//Function to Create Linked List 

void Create(int A[], int n)
{
    int i;
    struct Node *t,*last;

    //creating first node
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;
    
    //creating rest of the nodes
    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }

}

//Function to Display Linked List using Iterative Method
void Display(struct Node *p)
{
    while(p!=NULL){

        printf("%d ",p->data);

        p=p->next;

    }
}



//Function to Insert Node in Linked List

void SortedInsert(struct Node *p, int x)
{
    
    struct Node *t,*q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=t;
    }

    else{

        while(p && p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }
    }
    
}


//Driver Function

int main()
{



    int A[]={10,23,35,57,68};

    Create(A,5);

    SortedInsert(first,4);

    Display(first);

    printf("\n\n");

    return 0;

}