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
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    return(temp);
};
void append()
{
    int x=7;
    struct node *newnode;
    for(int i=0;i<6;i++)
    {
    newnode=create();
  //  cout<<endl<<"Enter the data to append in the list :: ";
   // cin>>x;
    newnode->data=x;
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
    x=x+10;
    }
}
void display()
{
    struct node * temp;
    temp=head;
    cout<<endl<<"CONTENT OF CIRCULAR LINKED LIST :: \n";
    while(temp!=tail)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<temp->data;
}


int main()
{
    append();
    display();
    return(0);
}
