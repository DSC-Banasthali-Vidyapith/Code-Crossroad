/*
EXPLAINATION: inplace reverse, revrsing the entire array followed by reversing starting elements till size of array-d, and finally reversing
the remaining array providing the required result, handling the corner case by modulous of d=d%size*/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
    void rotate(vector<int>& nums, int d) {
        //handling corner case of having d greater than provided n
          d = d % nums.size();
        //reversing the complete vector
        reverse(nums.begin(),nums.end());
        //reversing the values from the start till nums.size()-d th value
        reverse(nums.begin(),nums.begin()+nums.size()-d);
         //reversing the values from the nums.size()-d th value till the end
        reverse(nums.begin()+nums.size()-d,nums.end());
    }
int main() {
   int n,d,temp;
   cin>>n;
   cin>>d;
   vector<int> nums;

   //inputing array
   for(int i=0;i<n;i++)
   {
       cin>>temp;
      nums.push_back(temp);
   }

   //calling rotate function
   rotate(nums,d);

   //printing the resultant vector
   for(int i=0;i<n;i++)
   {
       cout<<nums[i];
   }
   return 0;
}
/*
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

//COMPLEXITIES ANALYSIS:

  O(1) space | O(n) time
  */