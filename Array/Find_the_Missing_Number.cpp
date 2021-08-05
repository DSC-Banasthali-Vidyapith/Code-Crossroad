/*
Algorithm: The user will give a list of n-1 integers. These integers will be in range of 1 to n.
A Variable named natural_sum is used which represents sum of n natural numbers. Firstly, 
natural_sum is calculated using n(n+1)/2 formula [here the formula is(n+1)(n+2)/2 
because the user is giving n-1 integers and there are n integers from which 1 is missing].
After this the array is traversed from start to end and each element is subtracted from
natural_sum. So, the result will be the missing number.
*/

#include<iostream>
using namespace std;

#define MAX 100

//Function to calculate the missing number
int missing_num(int a[],int n)
{
    int natural_sum=0;
    natural_sum=(n+1)*(n+2)/2;
    for(int i=0;i<n;i++)
    {
        natural_sum=natural_sum-a[i];
    }
    return natural_sum;
}

//Main function
int main()
{
    //Array to store list of integers
    int a[MAX]; 

    //Size of array
    int n;

    //Input size of array/no of integers
    cin >> n;

    //Input array/list of integers
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    //Missing number
    int miss_no=0;
    
    //Calling missing_num function and assigning its value to miss_no
    miss_no=missing_num(a,n);
    cout << "Missing number: " << miss_no;
    
    return 0;
}

/*
Time complexity: O(n)
Space Complexity: O(1)

Input:
no of integers: 4
list of integers: 1 2 3 5
Output:
Missing number: 4

Input:
no of integers: 6
list of integers: 6 2 1 4 3 7
Output:
Missing number: 5
*/