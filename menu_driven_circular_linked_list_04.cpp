#include<iostream>
#include<stdlib.h>
using namespace std;
int getlength();
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
void beg()
{
    struct node *newnode;
    newnode=create();
    cout<<"\nEnter the data to add at head ::";
    cin>>newnode->data;
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->next=head;
    }
    else
    {
        newnode->next=head;
        tail->next=newnode;
        head=newnode;
    }
}
void append()
{
    struct node *newnode;
    newnode=create();
    cout<<endl<<"Enter data to add at end :: ";
    cin>>newnode->data;
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
void input_at_random_position()
{
    int p,i=0,l;
    struct node *newnode,*temp;
    temp=head;
    cout<<endl<<"Enter the position to add data :: ";
    cin>>p;
    l=getlength();
    if(p<1 || p>l+1)
        cout<<"\nInvalid Position\n";
    else if(p==(l+1))
    {
        append();
    }
    else if(p==1)
    {
        beg();
    }
    else
    {
        if(head==NULL)
        {
            head=tail=newnode;
            newnode->next=head;
        }
        else
        {
            newnode=create();
            cout<<"\nEnter the data ::";
            cin>>newnode->data;
            for(i=1;i<p-1;i++)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }

    }
}

int getlength()
{
    struct node *temp;
    int c=0;
    temp=head;
    if(head==NULL)
    {
        return(c);
    }
  else
  {
    while(temp!=tail)
    {
        c++;
        temp=temp->next;
    }
    c++;
  }
    return(c);
}
void delete_head_node()
{
    struct node *temp;
    temp=head;
    int l=getlength();
    if(head==NULL)
        cout<<endl<<" LIST IS EMPTY \n";
    else if(l==1)
    {
        tail=head=NULL;
        free(temp);
    }
    else
    {
        tail->next=temp->next;
        head=head->next;
        free(temp);
    }
}
void delete_last_node()
{
    struct node *temp;
    temp=head;
    int l=getlength();
    if(head==NULL)
       cout<<"\nList is empty\n";
    else
    {
        for(int i=1;i<l-1;i++)
            temp=temp->next;
        temp->next=head;
        free(tail);
        tail=temp;
    }
}
void delete_random_node()
{
    int p,i=0,l;
    struct node *temp;
    temp=head;
    l=getlength();
    cout<<"\nTotal Number of nodes are :: "<<l;
    cout<<"\nEnter position to delete node :: ";
    cin>>p;
    if(p>l || p<1)
        cout<<endl<<"Invalid Location\n";
    else if(p==1)
    {
        delete_head_node();
    }
    else if(p==l)
    {
        delete_last_node();
    }
    else
    {
        for(i=1;i<p-1;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
}
void display()
{
    struct node *temp;
    temp=head;
    cout<<endl<<"CONTENT OF CIRCULAR LINKED LIST ::\n";
    if(temp==NULL)
    {
        cout<<"LIST IS EMPTY\n";
        return;
    }
  else
  {
    while(temp!=tail)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data;
  }
}


int main()
{
    int ch,l=0;
    while(1)
    {
        cout<<"\n1. ADD DATA AT END\n2. INSERT DATA AT RANDOM POSITION\n";
        cout<<"3. ADD AT BEGINNING\n4. DELETE RANDOM NODE\n";
        cout<<"5. NUMBER OF NODES IN LIST\n6. DISPLAY\n7. EXIT\n";
        cout<<"Enter your choice :: ";
        cin>>ch;
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: input_at_random_position();
                    break;
            case 3: beg();
                    break;
            case 4: delete_random_node();
                    break;
            case 5: l=getlength();
                    cout<<"\nNUMBER OF NODES IN LIST :: "<<l;
                    break;
            case 6: display();
                    break;
            case 7: exit(1);
            default:exit(1);
        }
    }
    return(0);
}
