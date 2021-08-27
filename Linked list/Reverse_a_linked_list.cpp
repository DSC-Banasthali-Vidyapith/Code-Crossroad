/*Algorithm:  Three pointers prev, traverse (as current) and temp(as next) will be used. We will iterate and shift them in such 
a manner that the linked list will get reverse.*/

#include<iostream>
using namespace std;

//Node structure
struct Node {
    int data;
    Node* next;
};

//Function to create a linked list
Node* create(int n,Node *head)
{
    Node *traverse=NULL;
    
    while(n!=0)
    {
        Node* nn = new Node();
        int d;
        cin >> d;
        nn->data = d;
        nn->next=NULL;
        
        if(head==NULL)
        {
            head=nn;
            traverse=nn;
        }
        else
        {
            traverse->next=nn;
            traverse=traverse->next;
        }
        
        n--;
    }
    
    return head;
}

//Function to reverse linked list
Node* reverse_list(Node* head)
{
    //previous node
    Node *prev=NULL;

    //Current node
    Node *traverse=NULL;
    
    traverse=head;
    while(traverse!=NULL)
    {
        //Next node
        Node *temp=NULL;

        temp=traverse->next;
        traverse->next=prev;
        prev=traverse;
        traverse=temp;
    }
    head=prev;
    
    return prev;
}

void display(Node *head)
{
    Node *traverse=NULL;
    traverse=head;
    while(traverse!=NULL)
    {
        cout << traverse->data << " ";
        traverse=traverse->next;
    }
}

//Main function
int main()
{
    Node* head=NULL,*traverse=NULL;

    //No of nodes in linked list
    int n;   
    cin >> n;
    
    //Calling create function in order to create linked list
    head=create(n,head);
    
    //Calling reverse_list function
    head=reverse_list(head);
    
    cout << "Reversed List:\n";
    
    //Displaying contents of linked list
    display(head);   
    return 0;
}

/*
Time complexity: O(n)
Space Complexity: O(1)

Input:
4
5 2 3 4
Output:
Reversed List:
4 3 2 5

Input:
6
10 20 -10 5 6 70
Output:
Reversed List:
70 6 5 -10 20 10
*/
