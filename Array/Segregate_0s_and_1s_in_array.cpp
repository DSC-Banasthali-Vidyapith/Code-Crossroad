/*Given an array of length N consisting of only 0s and 1s in random order.
Modify the array to segregate 0s on left side and 1s on the right side of the array.*/

#include<bits/stdc++.h>
using namespace std;

// Function to segregate 0s on left and 1s on right side of array
void segregate_0s_and_1s(int array[],int N)
{
	//stores number of zeros present in array
	int no_of_zeros=0;
	
	// Loop to count total number of 0s in array
	for(int i=0;i<N;i++)
	{
		if(array[i]==0)
			no_of_zeros+=1;
	}
	
	// Loop to modify the left side of array with 0s 
	for(int i=0;i<no_of_zeros;i++)
	{
		array[i]=0;
	}
	
	// Loop to modify the right(remaining) side of array with 1s
	for(int i=no_of_zeros;i<N;i++)
	{
		array[i]=1;
	}
		
}

int main()
{
	int N;
	cout<<"Enter the size of Array : ";
	cin>>N;
	
	int array[N];
	cout<<"Enter Array Elements : ";
	for(int i=0;i<N;i++)
	cin>>array[i];
	
	
	//function call
	segregate_0s_and_1s(array,N);
	
	//printing segregated array
	cout<<"\nSegregated Array of 0s and 1s is : ";
	for(int i=0;i<N;i++)
	cout<<array[i]<<" ";
	
	return 0;
}

/* Test Cases :
1.

Input :
Enter the size of Array : 5
Enter Array Elements : 0 1 0 1 0

Output :
Segregated Array of 0s and 1s is : 0 0 0 1 1

2.

Input :
Enter the size of Array : 10
Enter Array Elements : 0 1 1 1 0 0 1 0 1 1

Output :
Segregated Array of 0s and 1s is : 0 0 0 0 1 1 1 1 1 1

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

*/

