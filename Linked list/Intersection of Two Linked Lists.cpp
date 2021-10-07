#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2,int intersectVal);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}
int main()
{
    	int n1,n2,intersectVal;
    	cout<<"Enter size of 2 linked list : ";
        cin>>n1>>n2;
        
        cout<<"Enter first linked list : ";
        Node* head1 = inputList(n1);
        cout<<"Enter second linked list : ";
        Node* head2 = inputList(n2);
        cout<<"Enter intersection value : ";
        cin>>intersectVal;
        cout<<"Intersection point is : ";
        cout << intersectPoint(head1, head2,intersectVal) << endl;
    return 0;
}
//Function to find intersection point in Linked Lists.
int intersectPoint(Node* head1, Node* head2,int intersectVal)
{
    int l1=0,l2=0;
    struct Node *temp1=head1;
    struct Node *temp2=head2;
    //finding lengths of 2 linked list
    while(temp1->next!=NULL)
    {
        l1++;
        temp1=temp1->next;
    }
    while(temp2->next!=NULL)
    {
        l2++;
        temp2=temp2->next;
    }
    
    struct Node *tem1=head1;
    struct Node *tem2=head2;
    if(l1>l2)
        for(int i=0;i<(l1-l2);i++)
            tem1=tem1->next;
    else
        for(int i=0;i<(l2-l1);i++)
            tem2=tem2->next;
            
    //finding intersection point
    while(tem1->next!=NULL && tem2->next!=NULL)
    {
        tem1=tem1->next;
        tem2=tem2->next;
        if((tem1->data==tem2->data) && (tem1->data==intersectVal))
            return tem1->data;
    }
    return -1;
}


