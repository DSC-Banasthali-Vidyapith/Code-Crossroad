/*
Algorithm:If current subarray has sum greater than the given sum, then there is no possibility that adding elements to the current subarray the sum will be x (given sum). Idea is to use a similar approach to a sliding window. Start with an empty subarray, add elements to the subarray until the sum is less than x. If the sum is greater than x, remove elements from the start of the current subarray.
->create three variables, i, start=0, sum=0.
->Traverse the array from start to end.
->Update the variable sum by adding current element, sum = sum + array[i]
1)If the sum is greater than the given sum, update the variable sum as sum = sum – array[start], and update start as, start++.
2)If the sum is equal to given sum, print the subarray and break the loop.
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long int

void subarray_sum(vi a, int x)
{
    int n = a.size();
    int i, start = 0, sum = a[0];
    for (i = 1; i < n; i++)
    {
        while (sum > x && start < i - 1)
        {
            sum = sum - a[start];
            start++;
        }
        if (sum == x)
            break;
        else
            sum += a[i];
    }
    if (sum != x)
        cout << "Not Possible";
    else
    {
        for (int j = start; j < i; j++)
            cout << a[j] << " ";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vi a(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    subarray_sum(a, x);
    return 0;
}