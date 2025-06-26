#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
void printlist(Node *first);
int main()
{

    Node *first=NULL;
    //Node *last=first;
    int n=0;
    printf("The number of the nodes:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        Node *newnode=(Node *)malloc(sizeof(Node));
        newnode->next=NULL;
        printf("Node %d:",i);
        scanf("%d",&newnode->data);
        if(first==NULL)
        {
            first=newnode;
        }
        else
        {
            first->next=newnode;
        }
        first=newnode;
    }
    printlist(first);
}
void printlist(Node *first)
{
    while(first !=NULL)
    {
        printf("%d ",first->data);
        first=first->next;
    }
}
