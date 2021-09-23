/***

ALGORITHM:

- We input the number of integers, the integers (in a vector) and the target integer.
- Now, we start traversing on the integers in the vector one by one checking if its counterpart integer (the one when added to this integer adds up to the target) is present in the vector or not. 
- Thus, for O(1) of lookup of such element, we keep storing the elements in an unordered map. 
- As soon as we find a pair that adds up to the target integer, we insert the indices of the two integers and return it. 

***/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) 
{
	// unordered map whose key will be the integer and value will be the index at which that integer is present in the vector
        unordered_map<int, int> map;

        int n = nums.size();
        vector<int> ans;

	// traverse on the integers one by one
        for (int i = 0; i < n; i++)
        {
            if (map.count(target - nums[i]) > 0) // check if its counterpart is present in the map
            {
		// push the two indices in the answer vector and return it given the 'if' condition is true
                ans.push_back(map[target - nums[i]]); 
                ans.push_back(i);
                return ans; 
            }

	    // given 'if' condition is false, insert this integer in the map along with its index and continue looping on other integers
            map[nums[i]] = i; 
        }
        
        return ans;
}

int main()
{
	// input the number of integers
	int n;
	cin >> n;
	
	// input the integers
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];
		
	// input the target integer
	int target;
	cin >> target;
	
	// calling of twoSum() function that returns the vector containing answer
	vector<int> ans = twoSum(nums, target);	
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}


/***

TIME COMPLEXITY: O(N) 
Explanation: We traverse the vector only once using one for loop.

SPACE COMPLEXITY: O(N)
Explanation: In the worst case, we might store all the integers in the map. One such case can be when the two desirable integers are present at the first and the last index. 

***/

/***

EXAMPLE 1:

Input: n = 4, nums[] = {2, 4, 6, 11}, target = 10
Output: 1 2
EXAMPLE 2:

Input: n = 5, nums[] = {-1, -42, 0, 7}, target = -1
Output: 0 2

***/
