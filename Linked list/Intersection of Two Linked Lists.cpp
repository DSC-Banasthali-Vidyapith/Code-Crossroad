/*
AIM : Given two singly linked list intersecting eachother at a point . Find the intersection point.
====================================================================================================
INPUT : 
1. size of first linked list (say n1)
2. first linked list
3. size of second linked list (say n2)
4. second linked list
5. size of linked list that is common to both (say n3)
6. common linked list
=========================================================
OUTPUT : 
Data of the node at which both the linked list are intersecting.
=================================================================
APPROACH :
1. Assuming that only head of both the linked list are passed, length of both the linked list is calculated initially.
2. To find the point of intersection, traverse the linked list with bigger length by difference of lengths of 2 nodes (i.e abs(n1-n2)).
3. After that compare address of each node of both lists one by one until they get equal.
==========================================================================================
*/

#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

// Link list Node 
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


//This function takes input of linked lists
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

//	Function to find intersection point in Y shaped Linked Lists.
//	Here, length of both the linked list is calculated as l1 and l2 .
//	Later, the list with bigger length is traversed by absolute value of 
//	(l1-l2) times.

int intersectPoint(Node* head1, Node* head2)
{
    int l1=0,l2=0;
    struct Node *temp1=head1;
    struct Node *temp2=head2;
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
//    tem1 and tem2 are 2 pointers pointing to head1 and head2 of two linked list respectively.
    struct Node *tem1=head1;
    struct Node *tem2=head2;
    if(l1>l2)
    {
        for(int i=0;i<(l1-l2);i++)
        {
            tem1=tem1->next;
        }
    }
    else
    {
        for(int i=0;i<(l2-l1);i++)
        {
            tem2=tem2->next;
        }
    }
//  Now, both the lists are at equal distance from the intersecting point.
//	tem1 and tem2 are skipped one by one and if address of both the nodes get equal at any instance then 
//	that value of that node will be returned as output. 
    while(tem1->next!=NULL && tem2->next!=NULL)
    {
        tem1=tem1->next;
        tem2=tem2->next;
        if(tem1==tem2)
        {
            return tem1->data;
        }
    }
    return -1;
}


int main()
{
//	Size of 3 linked list are taken as input (say, n1,n2,n3)
//	n1-size of first linked list-size of linked list that is common to both
//	n2-size of first linked list-size of linked list that is common to both
//	n3-size of the coomon linked list
    	int n1,n2,n3;
		cout<<"Enter size of 1st linked list : "; 
        cin>>n1;
        cout<<"Enter size of 2st linked list : "; 
		cin>>n2;
		cout<<"Enter size of common linked list : "; 
		cin>>n3;
//  Taking input of each linked list by inputList function defined above.
        cout<<"Enter first linked list : ";
        Node* head1 = inputList(n1);
        cout<<"Enter second linked list : ";
		Node* head2 = inputList(n2);
		cout<<"Enter common linked list : ";
        Node* common = inputList(n3);
//  The common linked list is appended after both the lists.
//	temp is a pointer pointing to head1 i.e head of first linked list 
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
//	temp is a pointer pointing to head2 i.e head of second linked list         
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout <<"Intersection point : "<< intersectPoint(head1, head2) << endl;
    return 0;
}
/*
Test case 1:
3 1 2
3 6 9
10
15 30
Intersection point : 15
========================
Test case 2:
3 2 3
4 1 2
3 4
8 4 5
Intersection point : 8
========================
Expected Time Complexity: O(N+M)
Expected Auxiliary Space: O(1)
*/



