//Aim: Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction.
```c
#include <stdio.h>
#define len 100
int main()
{
    //Initialize array
   int arr[len];
   int N,D,i,j,first;
	printf("Enter size of array\n");
 	scanf("%d",&N);       //size of array
  	printf("Enter elements of array\n");
	  for(i=0;i<N;i++)
	  {
			  scanf("%d",&arr[i]);        //Input array elements
	  }
   printf("Enter no of rotation\n");
   scanf("%d",&D);
   printf("Original array: \n");
     for (int i = 0; i < N; i++)
	  {
	  		   printf("%d ", arr[i]);
     }
 	  //Rotate the given array by D times toward left or counter-clockwise direction
  	  for(int i = 0; i < D; i++)
  	  {
	   		 first = arr[0];  //Stores the first element of the array
	   		 for(j = 0; j < N-1; j++)
	     		 {
              		 arr[j] = arr[j+1];  //Shift element of array by one
	     		 }
      		arr[j] = first;
	  }
   printf("\n");
   printf("Array after rotate in counter-clockwise direction: \n");
   for(int i = 0; i < N; i++)
	  {
        printf("%d ", arr[i]);
	  }
    return 0;
}
```
