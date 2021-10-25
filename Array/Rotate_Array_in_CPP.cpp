/*
Algorithm: For rotating array left k times we will rotate array one by one i.r rotate array by one k times. For this we will use a for loop and 
call left_rotate_by_one() method k times.left_rotate_by_one() method will use a temp variable to rotate the array.
*/
#include<iostream>
using namespace std;

//Function to rotate array by one only
void left_rotate_by_one(int a[], int n)
{
    int i, temp;
    temp = a[0];
    for (i = 0; i < n - 1; i++)
        a[i] = a[i + 1];
        a[n-1] = temp;
}

//Function to rotate array
void leftRotate(int a[], int k, int n)
{
    for (int i = 0; i < k; i++)
        left_rotate_by_one(a,n);
}
  
//Main function
int main()
{               
    //Getting Input from user
    cout << "Enter size of array: ";
    int n;
    cin >> n;
        
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
        
    cout << "Enter value of k i.e no of rotations you want to make: ";
        int k;
        cin >> k;
        leftRotate(a,k,n);
        
        //Printing outputs
        cout << "Array after "  << k << " rotations: ";
        for(int i=0;i<n;i++)
        {
            cout << a[i] << " ";
        }
    }
/*
Time Complexity: O(n*k)
Space Complexity:   O(1)

Input:
Enter size of array: 7
1 2 3 4 5 6 7
Enter value of k i.e no of rotations you want to make: 2
Output:
Array after 2 rotations: 3 4 5 6 7 1 2

Input:
Enter size of array: 7
1 2 3 4 5 6 7
Enter value of k i.e no of rotations you want to make: 3
Output:
Array after 3 rotations: 4 5 6 7 1 2 3
*/