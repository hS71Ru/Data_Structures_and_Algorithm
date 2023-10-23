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

//Function to Reverse  Linked List using Array (Iterative Method)
void Reverse(struct Node *p){

    int *A, i=0;
    struct Node *q=p;

    A=(int *)malloc(sizeof(int)*Count(p));   //dynamic array

    while (q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while (q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
    
    
}



//Driver Function

int main()
{

    int A[]={3,5,7,9,12};

    Create(A,5);

    Reverse(first);

    Display(first);
    printf("\n\n");

    return 0;

}