#include<bits/stdc++.h>
using namespace std;


int minStep(int arr[], int n){
     int ans[n+1];
     for(int i=0; i<=n; i++)
        ans[i] = 0;

        ans[n] = 1;

        for(int i=n-1; i>=0; i--){
            for(int j=1; j<=arr[i] && i+j<=n; j++){
                ans[i] += ans[i+j];
            }
            
        }
        
        return ans[0];
}

int main(){
    #ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
    #endif

    int arr[] = {3,3,0,2,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minStep(arr, n); 

}