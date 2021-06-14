/*
Algorithm :
Initialize two pointers, slow and fast to head.
When traversing the list with a pointer slow, pointer fast traverses twice as fast.
When fast reaches the end of the list, slow must be in the middle.
*/

#include <iostream>
using namespace std;

//Node class
struct Node {
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

//Function to print the linked list
void displayList(Node *ptr) {
    while(ptr != NULL){
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL" << endl;
}

//Function to return middle element of linked list
Node* middleNode(Node *head) {
    Node *slow,*fast;
    slow = fast = head;
    while(fast && fast->next){
        //slow pointer moves single step
        slow = slow->next;
        //fast  pointer moves two steps
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    //Initialize an empty list
    Node *head = NULL;
    int size;
    cout << "Enter the size of linked list : " << endl;
    cin >> size;

    //Input the linked list
    Node *prev = NULL;
    cout << "Enter the linked list : " << endl;
    for (int i = 1; i <= size; i++)
    {
        int val;
        cout << "Enter the data for the node : " << endl;
        cin >> val;
        //Allocate node
        Node *newNode = new Node(val);
        if(head == NULL)
            head = newNode;
        else
            prev -> next = newNode;
        prev = newNode;
    }

    //Print linked list
    displayList(head);  

    //Get middle node and display if linked list is not empty
    Node *middle = middleNode(head);
    if(middle == NULL)
        cout << "Linked list is empty...No middle node exists!" << endl;
    else
        cout << "The middle node is : " << middle -> data <<endl;
    return 0;
}

/*
Input: LinkedList: 1->2->3->4->5
Output: 3
*/