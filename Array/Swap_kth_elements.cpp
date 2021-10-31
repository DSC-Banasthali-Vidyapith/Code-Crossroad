/*
Given an array arr of size N, swap the Kth element from beginning with Kth element from end.

Input: N = 8, K = 3

        arr[] = {1, 2, 3, 4, 5, 6, 7, 8}

Output: 1 2 6 4 5 3 7 8

Explanation: Kth element from beginning is 3 and from end is 6.

Input: N = 5, K = 2

        arr[] = {5, 3, 6, 1, 2}

Output: 5 1 6 3 2

Explanation: Kth element from beginning is 3 and from end is 1.

Expected Time Complexity: O(1)

Expected Auxiliary Space: O(1)

Constraints: 1 ≤ K ≤ N ≤ 10^5

1 ≤ arr ≤ 10^3

*/


/*
The algorithm
--------------
Idea is simple take kth element from last and kth element from start and just swap them.

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    /*
    Take the size of the array.
    */

    int n,k;
    cin>>n;

    /*
    Take the value of k from user.
    */
    cin>>k;

    /*
    Create an array of size n.
    */
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    /*
    The swaping part
    */


    swap(arr[k-1],arr[n-k]);

    /*
        Display the resultant array.
    */

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    /*
    And we are done.
    */

}


