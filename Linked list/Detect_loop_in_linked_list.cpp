/*
Algorithm: Two pointer have been used, 'a' and 'b'. 
If a cycle is present then at some point(iteration),
a and b will end up on the same node and if the cycle is not present 
then b will reach 'NULL', end of loop.
a starts from head and moves one node at a time. 
b starts from 2nd node and moves 2 nodes at a time. 
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

//This function is creating loop according to value of x
//(1 based indexing)
void loopForm(Node* head,Node* tail, int x)
{
	if(x==0)
	return;
	
	Node* temp=head;
	for(int i=1;i<x;i++)
		temp=temp->next;
	
	tail->next=temp;
}
    //Function to check if the linked list has a loop.
bool isLoop(Node* head)
{
        // your code here
        Node *a,*b;
        
        if(head == NULL)            // no node is present
            return false;
        
        if(head->next == NULL)      // one node with no cycle
            return false;
        
        if(head->next == head)      // one node with a self cycle
            return true;
        
        a = head;
        b = head->next;
        
        while(a != b && (b!=NULL && b->next!=NULL) )
        {
            a = a->next;
            b = b->next->next;
        }//if there is no loop b node will reach NULL
        
        if(a == b)
            return true;
        
        return false;
}
int main()
{
    //2 pointers : head and tail
    //head points to start of linked list
    //tail points to end of linked list(for loop formation)
	Node* head, *tail;
	int n,x,d;
	cin>>n>>d;
    
    //input linked list
	head=tail=new Node(d);
	for(int i=1;i<n;i++)
	{
		cin>>d;
		tail->next=new Node(d);
		tail=tail->next;
	}
	cin>>x;
	loopForm(head,tail,x);
		
	if (isLoop(head))
    cout << "True";
    else
    cout << "False";
    
	return 0;
}


//Time Complexity: O(N) 
//Auxiliary Space: O(1)

/*
Input: N = 3 value[] = {1,3,4} x = 2
Output: True

Input: N = 5 value[] = {1,2,3,4,5} x = 0
Output: False
*/