/*
    Aim: Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = { 2, 1, 10, 3, 4, 50, 6, 7 };
    int n = arr.size();
    int d = 2;  // number of left rotations

    // printing i + d th value of array
    for (int i = 0; i < n; i++)
        cout << arr[(i + d) % n] << " ";


    return 0;
}
    
