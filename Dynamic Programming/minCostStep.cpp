#include<bits/stdc++.h>
using namespace std;


int minStep(int arr[], int n){
     int ans[n+1];
     for(int i=0; i<=n; i++)
        ans[i] = 0;

        ans[n] = 0;

        for(int i=n-1; i>=0; i--){
            if(arr[i] == 0){
                ans[i] = INT_MAX;
            }else{
                int temp = ans[i+1];
                for(int j=2; j<=arr[i] && i+j<=n; j++){
                    temp = min(temp,ans[i+j]);
                }
                ans[i] = 1+temp;
            }
        }
        
        return ans[0];
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int arr[] = {3,2,4,2,0,2,3,1,2,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minStep(arr, n); 

}