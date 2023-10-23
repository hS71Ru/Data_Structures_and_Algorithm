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

void Insert(int index, int x)
{
    if(index==0){
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=first;
    first=t;
    }
    else{
        printf("\ninvalid Index");
    }
    
}


//Driver Function

int main()
{

    int A[]={3,5,7,9,12};

    Create(A,5);

    Display(first);

    Insert(3,100);

    printf("\n");

    Display(first);

    return 0;

}