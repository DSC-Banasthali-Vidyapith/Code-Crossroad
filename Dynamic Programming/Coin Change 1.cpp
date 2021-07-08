/*
Question: 
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.
*/
#include<iostream>

using namespace std;

int coinChange(int coins[],int n,int sum){
	int t[n+1][sum+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(coins[i-1]<=j)
				t[i][j]=t[i-1][j] + t[i][j-coins[i-1]];
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}

int main(){
	int n,sum;
	cout<<"Enter no. of coins:\t"<<endl;
	cin>>n;
	int coin[n];
	cout<<"Enter coins array:\t"<<endl;
	for(int i=0;i<n;i++)
		cin>>coin[i];
	cout<<"Enter sum:\t"<<endl;
	cin>>sum;
	cout<<coinChange(coin,n,sum);
	return 0;
}

/*
TEST CASES: 
I/P:
Enter no. of coins:
5
Enter coins array:
1 2 3
Enter sum:
5

O/P: 5
Time Complexity: O(n*sum)
Space Complexity: O(n) 
*/
