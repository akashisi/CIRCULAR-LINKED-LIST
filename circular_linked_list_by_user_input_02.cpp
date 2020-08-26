
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
    int x;
    struct node *newnode;
    newnode=create();
    cout<<endl<<"Enter the data to append in the list :: ";
    cin>>x;
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
    int ch;
    while(1)
    {
        cout<<endl<<"1. ADD DATA IN LAST IN CIRCULAR LINEKD LIST \n";
        cout<<"2. DISPLAY\n3. EXIT\n";
        cout<<"Enter your choice :: ";
        cin>>ch;
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: display();
                    break;
            case 3: exit(1);
            default:exit(1);
        }
    }
    return(0);
}
