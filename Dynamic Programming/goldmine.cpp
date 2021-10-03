#include<bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> arr){
    int ans = 0;
    if(n==1){
        for(int j=0; j<m; j++)
           ans += arr[0][j];
        return ans;
    }   
        
    int dp[n][m];

    for(int i=n-1; i>=0; i--)
      dp[i][m-1] = arr[i][m-1];

     ans=INT_MIN;  

    for(int j=m-2; j>=0; j--){
        for(int i=0; i<n; i++){
            if(i==0)
            dp[i][j] = arr[i][j]+max(dp[i][j+1],dp[i+1][j+1]) ;
            else if(i==n-1)
            dp[i][j] = arr[i][j]+max(dp[i-1][j+1], dp[i][j+1]);
            else 
            dp[i][j] = arr[i][j]+max(dp[i][j+1],max(dp[i-1][j+1], dp[i+1][j+1]));

        }
    } 

     for(int i=0; i<n; i++)
       ans = max(ans,dp[i][0]);

    return ans; 
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int n,m; cin >> n >> m;

   vector<vector<int>> arr(n);
   for(int i=0; i<n; i++)
     arr[i].resize(m);

    for(int i=0; i<n; i++)
      for(int j=0; j<m; j++)
         cin >> arr[i][j];

    cout << maxGold(n, m, arr);        

    return 0;
}