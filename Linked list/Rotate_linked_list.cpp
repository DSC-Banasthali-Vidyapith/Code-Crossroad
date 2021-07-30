/*Given the head of a linked list, rotate the list to the right by k places*/

/*
ALGORITHM- 
Step 1:find the length of the list as len
Step 2:attach head to last node of head(make the linked list circular)
Step 3:iterate to (len-k)th element,next element of this node would be the new head of linked list after rotation
Step 4:set (len-k)th element's link to NULL to break the circular linked list
*/
#include <iostream>
using namespace std;

//structure containing data part and link part
struct node
{
    int data;
    struct node *link;
};

//adds node at the end of a linked list
void append(struct node **head_ref, int num)
{
    struct node *temp, *r;

    if (*head_ref == NULL)
    {
        temp = new node();
        temp->data = num;
        temp->link = NULL;
        *head_ref = temp;
    }
    else
    {
        temp = *head_ref;
        //go to last node
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        //add node at end
        r = new node();
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

//displays the content of linked list
void display(struct node *head_ref)
{
    //traverse the entire linked list
    while (head_ref != NULL)
    {
        cout << head_ref->data << "->";
        head_ref = head_ref->link;
    }
    cout << "NULL" << endl;
}

//rotates the list to the right by k places
node *rotateRight(node *head_ref, int k)
{
    if (head_ref == NULL || head_ref->link == NULL || k == 0)
        return head_ref;

    int len = 1;
    node *temp = head_ref;
    //count the number of nodes in linked list
    while (temp->link)
    {
        temp = temp->link;
        len++;
    }

    //make linked list circular
    temp->link = head_ref;

    //to avoid extra rotations in case k>len
    k = k % len;

    int c = len - k;
    //Iterate to element before the Kth rotation
    while (c--)
    {
        temp = temp->link;
    }
    //next node of temp is the new head
    head_ref = temp->link;
    //break the circular linked list
    temp->link = NULL;

    return head_ref;
}

int main()
{
    node *head = NULL;
    int i, k;

    cout << "ENTER THE NUMBER OF ELEMENTS IN LINKED LIST ";
    cin >> i;
    for (int p = i; p > 0; p--)
    {
        printf("\nENTER THE ELEMENT ");
        int c;
        cin >> c;
        append(&head, c);
    }

    cout << "ENTER THE NUMBER OF PLACES BY WHICH THE LIST IS TO BE ROTATED ";
    cin >> k;
    cout << "LINKED LIST: \n";
    display(head);

    head = rotateRight(head, k);
    cout << "\nROTATED LINKED LIST: \n";
    display(head);

    return 0;
}

/*
SAMPLE INPUT 1:
ENTER THE NUMBER OF ELEMENTS IN LINKED LIST 5

ENTER THE ELEMENT 4

ENTER THE ELEMENT 7

ENTER THE ELEMENT 1

ENTER THE ELEMENT 9

ENTER THE ELEMENT 6
ENTER THE NUMBER OF PLACES BY WHICH THE LIST IS TO BE ROTATED 3
LINKED LIST:
4->7->1->9->6->NULL

ROTATED LINKED LIST:
1->9->6->4->7->NULL

SAMPLE INPUT 2:
ENTER THE NUMBER OF ELEMENTS IN LINKED LIST 5

ENTER THE ELEMENT 7

ENTER THE ELEMENT 9

ENTER THE ELEMENT 6

ENTER THE ELEMENT 4

ENTER THE ELEMENT 1
ENTER THE NUMBER OF PLACES BY WHICH THE LIST IS TO BE ROTATED 26
LINKED LIST:
7->9->6->4->1->NULL

ROTATED LINKED LIST:
1->7->9->6->4->NULL

TIME COMPLEXITY -> O(n)
SPACE COMPLEXITY -> O(1)
*/