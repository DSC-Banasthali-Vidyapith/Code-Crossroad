// leetcode - [https://leetcode.com/problems/partition-equal-subset-sum/]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        
        int sum=0;
        for(auto &x : nums) sum += x;
        
        if(sum%2 != 0) return false;
        
        int targetSum = sum/2;
        
        // table
        bool ans[n+1][targetSum+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=targetSum; j++){
                if(j==0) ans[i][j] = true;
                
                else if(i==0) ans[i][j] = false;
                
                else {
                    if(j<nums[i-1]){
                        ans[i][j] = ans[i-1][j];
                    }else{
                        ans[i][j] = ans[i-1][j-nums[i-1]] || ans[i-1][j];
                    }
                }
            }
        }
            
        return ans[n][targetSum];
    }
};