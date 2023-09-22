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


//Function to Count Nodes of Linked List using Recursion

int RCount(struct Node *p)
{
    if(p!=NULL)
        return RCount(p->next)+1;                   //recursive Function 
    else 
        return 0;

    
}


//Driver Function

int main()
{

    int A[]={3,5,7,9,17,42,63,445};

    Create(A,8);

    printf("Length is %d",RCount(first));

    return 0;

}