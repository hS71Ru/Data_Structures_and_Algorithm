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

//Function to Count Nodes of Linked List using Iterative Method

int Count(struct Node *p)
{
    int l=0;
    while(p!=NULL){

        l++;

        p=p->next;

    }
    return l;
}

//Function to Reverse  Linked List using Sliding Pointers (Iterative Method)
void Reverse(struct Node *p){

    
    struct Node *q=NULL, *r=NULL;

    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    
    
}

//Function to Reverse  Linked List using Sliding Pointers (Recursive Method)
void RReverse(struct Node *q, struct Node *p){
    if(p!=NULL){
        RReverse(p, p->next);
        p->next=q;
    }
    else{
        first=q;
    }
}



//Driver Function

int main()
{

    int A[]={20, 70, 60, 55, 27, 38, 49};

    Create(A,7);

    RReverse(NULL, first);

    Display(first);
    printf("\n\n");

    return 0;

}