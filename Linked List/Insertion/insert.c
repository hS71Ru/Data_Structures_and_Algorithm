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

//Function to Count Nodes in Linked List
int Count(struct Node *p)
{
    int c=0;
    while(p!=NULL){

        c++;

        p=p->next;

    }
    return c;
}

//Function to Insert Node in Linked List

void Insert(struct Node *p, int index, int x)
{
    
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index < 0 || index > Count(p)){
        return;
    }

    if(index==0){
        t->next=first;
        first=t;
    }
    
    else{

        for(int i=0;i<index-1;i++){
            p=p->next;
        }
            t->next=p->next;
            p->next=t;
        
    }
    
    
}


//Driver Function

int main()
{



    int A[]={3,5,7};

    Create(A,3);

    Insert(first,3,19);

    Display(first);

    

    return 0;

}