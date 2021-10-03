/*
Given an integer array nums sorted in non-decreasing order, the task is to remove the duplicates in-place such that each unique 
element appears only once. The relative order of the elements should be kept the same. And, returning k after placing the final 
result in the first k slots of nums (where k is the no of elements left after removing duplicates).

Algorithm - To solve this we will use two pointers namely i amd j. i pointing at 0th position and j pointing at 1st position.
If elements at i and j position are same then we will simply increement j otherwise firstly we will increement i and then store
nums[j] at that ith position. Here, k will store the no of elements which are non repetitive (from start) so it will store 
i+1 after each iteration. At last removeDuplicates function will return value of k. 
*/
#include<bits/stdc++.h>
using namespace std;

//Function to remove duplicates in an array which will return value of k
int removeDuplicates(vector<int>& nums)
{
    //Initializing pointers
    int i=0,j=1,k=0;

    if(nums.size()==1)
        return 1;
    while(i<nums.size() && j<nums.size())
    {
        if(nums[i]==nums[j])
            j++;
        else
        {
            nums[++i]=nums[j];
        }
        k=i+1;
    }
    
    return k;
}

//Main Function
int main()
{
    //Take size of array from user
    cout << "Enter size of array: ";
    int n;
    cin >> n;

    //Declaration of vector which will hold elements
    vector<int> nums(n);

    //Take elements of array from user
    cout << "Enter elements of array in sorted order: ";
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }

    //Calling removeDuplicates function and getting value of k
    int k = removeDuplicates(nums);

    cout << "Array after removing duplicates is: ";
    for(int i=0;i<k;i++)
    {
        cout << nums[i] << " ";
    }
}
/*
Time Complexity: O(n)
Space Complexity: O(1)

Input:
Enter size of array: 3
Enter elements of array in sorted order: 1 1 2
Output:
Array after removing duplicates is: 1 2 

Input:
Enter size of array: 10
Enter elements of array in sorted order: 0 0 1 1 1 2 2 3 3 4
Output:
Array after removing duplicates is: 0 1 2 3 4 
*/