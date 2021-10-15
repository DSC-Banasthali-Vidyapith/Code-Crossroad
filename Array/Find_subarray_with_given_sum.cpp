/*
Algorithm:If current subarray has sum greater than the given sum, then there is no possibility that adding elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.
->create three variables, i, start=0, sum=0.
->Traverse the array from start to end.
->Update the variable sum by adding current element, sum = sum + array[i]
1)If the sum is greater than the given sum, update the variable sum as sum = sum – array[start], and update start as, start++.
2)If the sum is equal to given sum, print the subarray and break the loop.
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int

// Function to print subarray for a given sum if possible
void subarray_sum(vi a, int x)
{
    int n = a.size();
    int i, start = 0, sum = a[0];
    
    // Add the element one by one to sum and check 
    // if sum exceed x then remove start index
    for (i = 1; i < n; i++)
    {
        // if sum exceeds x, just remove the start index
        while (sum > x && start < i - 1)
        {
            sum = sum - a[start];
            start++;
        }
        // If sum is equal to x, break the loop
        if (sum == x)
            break;
        
        //else add the current element to sum
        else
            sum += a[i];
    }
    
    if (sum != x)
        cout << "Not Possible";
    
    else
    {
        for (int j = start; j < i; j++)
            cout << a[j] << " ";
    }
    return;
}

int main()
{
    // input number of integers
    int n;
    cin >> n;
    
    // vector to store list of integers
    vi a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // input required sum 
    int x;
    cin >> x;
    
    // calling subarray_sum function to find the required subarray if possible
    subarray_sum(a, x);
    return 0;
}

/*
Time complexity: O(n)
Space Complexity: O(1)
Input:
6
32 12 4 28 9 1
41
Output:
4 28 9 
Input:
10
34 90 45 63 72 23 12 8 3 1
50
Output:
Not Possible
*/
