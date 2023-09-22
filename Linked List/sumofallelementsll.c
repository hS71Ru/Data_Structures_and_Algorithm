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

//Function to Sum of All elements of Linked List using Iterative Method

int AddElements(struct Node *p)
{
    int sum=0;
    while(p!=NULL){

        
        sum+=p->data;
        p=p->next;

    }
    return sum;
}


//Function to Sum of All Elements of Linked List using Recursion

int RAddElements(struct Node *p)
{
    if(p==NULL)
        return 0;                                
    else 
        return RAddElements(p->next)+p->data;           //recursive Function 

    
}


//Driver Function

int main()
{

    int A[]={3,5,7,9,12,42,63,445,1232};

    Create(A,9);

    printf("Sum is %d",RAddElements(first));

    return 0;

}