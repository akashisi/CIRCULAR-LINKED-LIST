#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;

struct node *create()
{
    return((struct node *)malloc(sizeof(struct node)));
};

void append(int arr[],int n)
{
    struct node *newnode;
    for(int i=0;i<n;i++)
    {
        newnode=create();
        newnode->data=arr[i];
        if(head==NULL)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        newnode->next=head;
    }
}
void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF CIRCULAR LINKED LIST \n";
    while(temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
}

int main()
{
    int n,a[]={9,0,4,5,6,7,0,0,6,4};
    n=sizeof(a)/sizeof(a[0]);
    append(a,n);
    display();
    return(0);
}
