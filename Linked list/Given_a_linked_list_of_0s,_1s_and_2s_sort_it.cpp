/*
Algorithm :
Maintain the frequencies of 0,1,2 and fill the Linked list in sorted order.
*/

#include<iostream>
#include<unordered_map>


using namespace std;

//Node Class
struct node{
    int data;
    node *next;

    node(int val)
    {
        data=val;
        next=NULL;
    }
};

// Function to print Linked list
void display(node *temp)
{
    cout<<"\nLinked List: ";

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

}

//Function to sort Linked list
void sort(node *head)
{
   unordered_map<int,int>m;
    
    node *temp=head;


    // Maintaining frequencies of 0,1,2 in unordered map
    while(temp!=NULL)
    {
        m[temp->data]++;
        temp=temp->next;

    }

    temp=head;

    while(temp!=NULL)
    {
        // if the frequency of 0 is more than 0, then filling the Linked list that no of times with 0.
        if(m[0]!=0)
        {
            temp->data=0;
            m[0]-=1;
            
        }
        else
        {
            //if the frequency of 1 is more than 0, then filling the Linked list that no of times with 1.
            if(m[1]!=0)
            {
                 temp->data=1;
                m[1]-=1;
            }

            else
            {
                //if the frequency of 2 is more than 0, then filling the Linked list that no of times with 2.
                temp->data=2;
                m[2]-=1;

            }
        }
        temp=temp->next;
    }
}


int main()
{
    int n,val;
    cout<<"Enter size of Linked list= ";
    cin>>n;

    //Initialize an empty list
    node *head=NULL,*temp,*newnode;

    // Input the Linked list
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter data of node= ";
        cin>>val;
        
        //Allocate node
        newnode= new node(val);

        if(head==NULL)
        {
             head=newnode;
             temp=head;

        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
            
    }

    // Printing original Linked list
    display(head);

    sort(head);

    // Printing sorted Linked list
    display(head);

    return 0;
}


/*
Input: 
size: 5
2->2->0->0->1
Output: 0->0->1->2->2

Input: 
size: 7
1->2->1->2->1->1->2
Output: 1->1->1->1->2->2->2


Time Complexity: O(N)
Space Complexity: O(1)
*/