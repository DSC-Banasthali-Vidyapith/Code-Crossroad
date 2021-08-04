/* 
Algorithm :
We will use sliding window technique and deque to store index of array elements in decreasing order. 
1. Start Traversing the array 
2. If deque is empty directly add the index of element in deque otherwise check that previous element of deque from front is 
out of range or not. If out of range then, pop front index from queue. 
3. If the current element (a[i]) is greater than element at index obtained from back of deque then keep poping back and then push 
the ith index.
4. If size of window becomes equal to k then store the element present at index obtained from front of deque in ans vector.
*/

#include <bits/stdc++.h>

using namespace std;

// Function to find maximum of all subarrays of size k
vector<int>max_of_subarrays(int a[], int n, int k)
{
    deque<int>q;
    vector<int>ans;
        
        
    for(int i=0;i<n;i++)
    {
        // if q is not empty and index at front of deque is out of range
        if(!q.empty() && q.front()==(i-k))
            q.pop_front(); //poping front index

        // if q is not empty and elements corresponding to index from back of deque are less than current array value    
        while(!q.empty() && a[q.back()]<a[i])
            q.pop_back(); //pop back indexes
             
        q.push_back(i); //pushing elemet in deque in decreasing order
            
        if(i>=(k-1)) // if size of window is k
            ans.push_back(a[q.front()]); 
            
                
    }
        
    return ans;
}



int main() 
{
    int n,k,i;
	cout<<"Enter size of array= "; //taking inputs
    cin>>n;

    int a[n];
    cout<<"Enter array= ";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"Enter size of subarray k= ";
    cin>>k;
	
	vector<int>ans=max_of_subarrays(a,n,k);

    //printing answer vector containing max of all subarrays of size k
    for(i=0;i<ans.size();i++)
        cout<<ans[i];
	
	return 0;
}  

/*
Testcase 1
Input:
n=9, k=3
arr[]= 1 2 3 1 4 5 2 3 6

Output: 
3 3 4 5 5 5 6


Testcase 2
Input:
n=8, k=5
arr[]= 4 2 6 8 1 5 9 0

Output: 
8 8 9 9 


Time Complexity: O(n)
Space Complexity: O(k)

*/
