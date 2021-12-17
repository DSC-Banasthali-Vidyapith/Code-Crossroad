#include<bits/stdc++.h>
using namespace std;

// recursion
bool checkSubset(int n, vector<int> arr, int targetSum){
    if(targetSum == 0)
        return true;
    if(n==0)
        return false;

   
    int num = arr[n];
    if(num > targetSum)
     return checkSubset(n-1, arr, targetSum);

    return checkSubset(n-1,arr,targetSum-num) || checkSubset(n-1,arr,targetSum) ;     
}

// DP
bool checkSubsetDP(int n, vector<int> arr, int sum){
   
    int ans[n+1][sum+1];
 
     for(int i = 0; i <= n; i++)
        ans[i][0] = 1;
    
    for(int j = 0; j <= sum; j++)
        ans[0][j] = 0;
    

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
                 if(arr[i-1] > j)
                   ans[i][j]=ans[i-1][j];
                else 
                  ans[i][j] = ans[i-1][j] || ans[i-1][j-arr[i-1]];  
                 
        }
    }
    return ans[n][sum];
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int n; cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++)
         cin >> arr[i];
    int targetSum; cin >> targetSum;
    //cout << checkSubset(n-1, arr, targetSum);        
    cout << checkSubsetDP(n-1, arr, targetSum);        

    return 0;
}