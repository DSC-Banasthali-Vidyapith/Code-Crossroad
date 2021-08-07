/*Given an array of length N consisting of only 0s and 1s in random order.
Modify the array to segregate 0s on left side and 1s on the right side of the array.*/

/* ALGORITHM :
We maintain two indices, left which starts from index 0 and right which starts from N-1 where N is number of elements in the array.
Then Move left forward till it encounters a 1, similarly decrement right until a zero is encountered. 
If left is less than right, swap elements at these two indice and repeat again.

1. Set left = 0 and right = N-1
2. While left < right 
		if a[left] is 0 then left++
		if a[right] is 1 then right–- ;
		if left < right then swap(a[left], a[right])

*/

#include<bits/stdc++.h>
using namespace std;

// Function to segregate 0s on left and 1s on right side of array
void segregate_0s_and_1s(int array[],int N)
{
	
	int left=0,right=N-1;
	
 	while (left<right)
        {
        	// Incrementing left index while there is 0 at left index 
        	while(array[left]==0 && left<right)
            	left=left+1;
 
        	// Decrementing right index while there is 1 at right index
        	while(array[right]==1 && left<right)
            	right=right-1;
 
        	// If left is smaller than right then swap array[left] and array[right]
        	if (left<right)
        	{
            	array[left]=0;
            	array[right]=1;
            	left=left+1;
            	right=right-1;
        	}
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

