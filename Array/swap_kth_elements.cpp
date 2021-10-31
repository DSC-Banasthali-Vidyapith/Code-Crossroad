#include<iostream>

using namespace std;

int main()
{
 int t;
 cin>>t;
 while(t--)
 {
  int a[100],i;
  int n;
   int k;
  cin>>n>>k;;
 

  for(i=0; i<n; i++)
  {
   cin>>a[i];
  }
  int temp;
  temp=a[k-1];
  a[k-1]=a[n-k];
  a[n-k]=temp;
  for(i=0; i<n; i++)
  {
   cout<<a[i]<<" ";
  }
  cout<<endl;
 }
}