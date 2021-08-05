/*
To set a bit, we make that bit as 1.
1U will be used to determine a value with the Kth bit set already.
1U is an unsigned value with only bit 0 set and all the other bits cleared.
    (1U << 0) indicates - create value with 0 bit set i.e. 00000000000000000000000000000001
    (1U << 1) indicates - create value with 1 bit set i.e. 00000000000000000000000000000010
    and so on ..
Bitwise | operator will be used to set Kth bit in given number N, using the above determined value.
*/

#include <iostream>
using namespace std;

unsigned int setBit(int N, int K){
    
    //setValue will be a value with Kth bit set already
    unsigned int setValue = (1U << K);

    //set Kth bit in N using setValue and return combined result
    return setValue | N; 
}

int main(){
    int N, K;
    cin>>N>>K;
    unsigned int result = setBit(N, K);
    cout<<result;
    return 0;
}

/*
Input: N = 18, K = 2
Output: 22
Input: N = 25, K = 3
Output: 25

Time Complexity: O(1)
Space Complexity: O(1) 
*/