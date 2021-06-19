/* Given an array of positive and negative integers. We have to find subarray having maximum sum */
#include<iostream>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
int kadaneAlgo(int arr[], int n)
{
    // stores the maximum sum subarray found so far
    int max_so_far = INT_MIN;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    for(int i=0;i<n;i++)
    {
		max_ending_here+=arr[i];
		if(max_so_far<max_ending_here)
		{
			max_so_far=max_ending_here;
		}
		if(max_ending_here<0)
		{
			max_ending_here=0;
		}
    }
    return max_so_far;
}
 
int main()
{
	int n,max_sum;
     cout<<"Enter the size of the array: ";
     cin>>n;
     int arr[n];
     cout<<"Enter Array Elements: "<<endl;
     for(int i=0;i<n;i++)
     	cin>>arr[i];
     max_sum=kadaneAlgo(arr,n);
     cout <<"The maximum sum of a contiguous subarray is :"<<max_sum;
 
    return 0;
}

/*
	Test Case-1
	I/P: arr[]={-3,4,-1,-2,1,5}
	O/P: The maximum sum of a contiguous subarray is :7
	
	Test Case-2
	I/P: arr[]={-1,-2,-3,-4}
	O/P: The maximum sum of a contiguous subarray is :-1
	
	Expected Time Complexity: O(n)
	Expected Auxiliary Space: O(1)
*/
