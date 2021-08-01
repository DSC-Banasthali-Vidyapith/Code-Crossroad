/*
Question: 
Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.

Approach:
Coin change problem has the property of the optimal substructure i.e., the optimal solution of a problem incorporates the optimal solution to the subproblems. Here in this problem we have a choice of whether to chose or not choose a particular coin. This makes it a variation of unbounded knapsack problem. 
1)So we make a table of length (n+1) and width (sum+1) to insert the answers of subproblems.
2)Then we have a look at our first row and column and we observe:
	a. When i==0 ie we have no coins, then there is not a single way to form the sum hence t[i][j]=0
	b. When j==0 where we need coins to sum up to 0, there is one way ie not not include the coins at all hence t[i][j]=0
3)To count the total number of solutions, we can divide all set solutions into two sets. 
	a. Solutions that do not contain mth coin (or Sm). 
	b. Solutions that contain at least one Sm. 
*/
#include<iostream>

using namespace std;

//Coin change function
int coinChange(int coins[],int n,int sum){
	int t[n+1][sum+1]; //table for storing the results of sub problems
	for(int i=0;i<=n;i++){// initializing as per step 2
		for(int j=0;j<=sum;j++){
			if(i==0)
				t[i][j]=0;
			if(j==0)
				t[i][j]=1;
		}
	}
	
	for(int i=1;i<=n;i++){//filling the table as per step 3
		for(int j=1;j<=sum;j++){
			if(coins[i-1]<=j)
				t[i][j]=t[i-1][j] + t[i][j-coins[i-1]];
			else
				t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
}

//Driver function
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
_________________________________
I/P:
Enter no. of coins:
10
Enter coins array:
2 5 3 6
Enter sum:
5

O/P: 5
_________________________________
I/P:
Enter no. of coins:
4
Enter coins array:
1 2 3
Enter sum:
4

O/P: 5
__________________________________
Time Complexity: O(n*sum)
Space Complexity: O(n) 
*/
