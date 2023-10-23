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


//Function to Display Linked List using Recursion

void RDisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        RDisplay(p->next);                   //recursive Function

    }
}


//Driver Function

int main()
{

    int A[]={3,5,7,9,12};

    Create(A,5);

    RDisplay(first);

    return 0;

}