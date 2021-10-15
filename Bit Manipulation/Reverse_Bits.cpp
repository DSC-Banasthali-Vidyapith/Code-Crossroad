/*
To reverse the bits of an 32 bit unsigned integer and returning its decimal equivalent
we create a new unsigned integer "ans" initialized with 0 adding bits to it
such that it contains reversed bits of A.
We acheive it by adding ith bit of A to (32 - i + 1)th position of "ans"
Therefore we keep dividing A by 2 (to check every bit) and if find a "1" at position i,
we add a "1" in "ans" at (32-i+1)th position.
    ans += (1<<k) sets the (k+1)th bit of ans
    therfore, we do ans += 1<<(32-i) to set the bit at (32 - i + 1)th position
We stop looping once A is reduced to 0 and return the "ans".
*/

#include <iostream>

using namespace std;

unsigned int reverseBits(unsigned int A) {      // function with A passed as argument

    // initializing ans to 0 and i(position of current bit) to 1 as we start checking from 1st bit
    unsigned int ans = 0, i = 1;

    // while loop interates untill A is reduced to 0
    while(A>0) {

        // If we encounter a "1" in A's bits
        if(A%2==1)
            ans += 1<<(32-i);   // set desired bit of ans

        // discard last bit as it is checked
        A = A / 2;

        // increase the postion by 1
        i++;
    }

    // return the ans
    return ans;
}

int main() {

    // initializing input variable A
    unsigned int A;

    // taking input varible
    cin>>A; 

    // calling the function with A passed as argument and printing the output to the console
    cout<<reverseBits(A);

    return 0;
}

/*
Testcases:
#1
Input: A = 1
Output: 2147483648

#2
Input: A = 2147483649
Output: 2147483649

Time Complexity: O(log(A))
Space Complexity: O(1)
*/
