/******************************************************************************

Question link: https://leetcode.com/problems/third-maximum-number/

Q: Given an integer array nums, return the third distinct maximum number in this array.
    If the third maximum does not exist, return the maximum number.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int thirdMax(vector <int> &a)
{
    int n=a.size();
    sort(a.begin(),a.end());
    int index=n-1, i, Count=0;
    
    while(index>=0)
    {
        Count++;
        i=index-1;
        
        //to check all the values with same value as a[index]
        while(i>=0&&a[i]==a[index])
            i--;
            
        //if there is no third distinct element
        if(i==-1)
            return a[n-1];
        index = i;
        
        //found 2 bigger elements before?
        if(Count==2)
            return a[index];
    }
    return -1;
}
int main()
{
    vector <int> a={3,2,1};
    cout<<thirdMax(a)<<'\n';   
    //Solution should be 1
}


/******************************************************************************
Test cases are taken from leetcode

Test Case 1

Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Test Case 2

Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.

Time Complexity: O(NlogN)
Space Complexity: O(1)
******************************************************************************/