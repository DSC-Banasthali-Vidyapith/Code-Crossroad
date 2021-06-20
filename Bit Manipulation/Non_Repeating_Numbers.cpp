/*
Algorithm:
-> Take XOR of all elements. Since all numbers except two are repeated once,
   the XOR of all elements will actually be the XOR of the non-repeating elements.
-> Take the rightmost set bit mask of the calculated XOR.
-> Divide the elements in two sets according to the rightmost set bit
   and do XOR in each set and we get the non-repeating elements.
*/

#include <iostream>
using namespace std;

//Function to print the array
void printArray(int arr[], int size){
    cout << "The array elements are : " << endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

//Function which finds the two non repeating elements and returns it as an array
int *findNonRepeating(int arr[], int size){
    int xorArr = 0;
    for(int i = 0; i < size; i++){
        xorArr ^= arr[i];
    }
    //finding rightmost set bit mask
    int rsb = xorArr & -xorArr;
    //let x and y be the non repeating elements
    int x = 0;
    int y = 0;
    //Using new to allocate memory dynamically otherwise normal array will be allocated memory in stack
    //and once our function is out of scope all stack memory will be automatically cleared
    int *ans = new int(2);
    //Making two sets according to the rightmost set bit
    for(int i = 0; i < size; i++){
        if(arr[i] & rsb){
            x ^= arr[i];
        }
        else{
            y ^= arr[i];
        }
    }
    ans[0] = x;
    ans[1] = y;
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array : " << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //Printing the array
    printArray(arr,n);

    auto ans = findNonRepeating(arr,n);
    cout << "The non repeating elements are : " << endl;
    cout << ans[0] << " " << ans[1] << endl;
}

/*
Input: 2, 4, 7, 9, 2, 4
Output: 7 9

Input: 2, 3, 10, 15, 11, 2, 3, 11
Output: 10 15
*/