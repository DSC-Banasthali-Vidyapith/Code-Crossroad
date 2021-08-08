/*
Algorithm: The user will give elements of array and the value of k. We have to find 
the number of subarrays having product less than k. In this we will use sliding window 
technique.
Lets say we have a window between start(s) and end(e), and the product of all elements of it 
is prod < k. Now, let’s try to add a new element x. There are two possible cases.

Case 1. prod*x < k 
This means we have to move the window’s right bound(e) one step further. 
The no of subarrays possible is: 1 + (e-s).

Case 2. prod*x >= k
This means we must first adjust the window’s left border(start) so that the product is again less than k. After that, we can apply the
formula from Case 1.
*/
#include<iostream>
using namespace std;

#define MAX 1000

//Function to calculate no of subarrays having product less than k
int SubarraysHavingProductLessThanK(int a[],int k,int n)
{
    //start of window pointing at start of array
    int s=0;    

    //end of window
    int e=0;    

    //to track product of elements of the subarray 
    int prod=1; 

    //to count no of subarrays
    int count=0;    

    //If product is less than or equal to 1 then there is no subarray possible
    if(k<=1)   
        return 0;
    while(e<n)
    {
        //Update the product
        prod=prod*a[e];

        //If product gets grater than k then we have to move start(s) further
        while(prod>=k && s<e)
        {
            prod=prod/a[s];
            s++;   
        }

        //If product is less than k then it satisfies the condition and we have to update the counter and increment e
        if(prod<k)
        {
            count=count+e-s+1;
            e++;
        }
    }
    return count;
}

//Main Function
int main()
{
    //Array to store elements
    int a[MAX];

    //Size of array
    int n;

    //Input size of array
    cout << "Enter size of array: ";
    cin >> n;

    //Input elements of array
    cout << "Enter elements of array: ";
    for(int i=0;i<n;i++)
        cin >> a[i];

    int k;

    //Input value of k
    cout << "Enter value of k: ";
    cin >> k;
    
    int res;

    //Calling SubarraysHavingProductLessThanK function and assigning its value to res
    res=SubarraysHavingProductLessThanK(a,k,n);
    cout << "Subarrays having product less than k: " << res;
}
/*
Time complexity: O(n)
Space Complexity: O(1)

Input:
Enter size of array: 4
Enter elements of array: 1 2 3 4
Enter value of k: 10
Output:
Subarrays having product less than k: 7

Input:
Enter size of array: 7
Enter elements of array: 1 9 2 8 6 4 3
Enter value of k: 100
Output:
Subarrays having product less than k: 16
*/