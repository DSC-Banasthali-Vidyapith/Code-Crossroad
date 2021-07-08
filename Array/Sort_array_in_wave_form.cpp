/*
Algorithm:All elements at even index (0, 2, 4, ..)are greater 
than their adjacent odd elements.
->Traverse all odd positioned(index) elements of input array, and 
1) If current element is greater than previous even element, swap them. 
2) If current element is greater than next even element, swap them. 
*/

#include<bits/stdc++.h>
using namespace std;

//function to sort array in wave form 
//a1 >= a2 <= a3 >= a4 <= a5.....
//(considering the increasing lexicographical order).
void fun(vector<int>& arr,int n)
{
	for(int i=1;i<n;i+=2)
	{
		if(arr[i]>arr[i-1])
		swap(arr[i],arr[i-1]);
		
		if(arr[i]>arr[i+1]&&i<n-1)
		swap(arr[i],arr[i+1]);
	}
}

//main function
int main()
{
	int n,val;
	cin>>n;
	vector<int> v;
	//input array
	for(int i=0;i<n;i++)
	{
		cin>>val;
		v.push_back(val);
	}
	fun(v,n);//function calling
	
	//output array in wave form
	for(int i=0;i<n;i++)
	{
		cout<<v[i]<<" ";
	}
}

/*
Input: n = 5 arr[] = {1,2,3,4,5}

Output: 2 1 4 3 5

Input: n = 6 arr[] = {2,4,7,8,9,10}

Output: 4 2 8 7 10 9

Expected Time Complexity: O(N)

Expected Auxiliary Space: O(1)
*/