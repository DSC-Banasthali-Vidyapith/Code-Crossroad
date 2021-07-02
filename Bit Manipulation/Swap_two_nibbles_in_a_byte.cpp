/*
Bitwise & operator will be used to split the byte into two nibbles.
Bitwise shift operators(>> and <<) will be used to swap the original places of the nibbles.
Bitwise | operator will be used to join the swapped nibbles.
If given number N = 40 i.e. 00101000
    First nibble : (0010)
    Second nibble : (1000)
*/

#include <iostream>
using namespace std;

int swapNibbles(int N){
    
    //extract the first nibble (leftmost)
    int first_nibble = N & 0xF0;
    //extract the second nibble (rightmost)
    int second_nibble = N & 0x0F;

    //Shift the first nibble to the right
    first_nibble >>= 4;
    //Shift the second nibble to the left
    second_nibble <<= 4;
        
    //combine the newly swapped nibbles
    return first_nibble | second_nibble;
}

int main() {
	int N;
	cin>>N;
	int result = swapNibbles(N);
	cout<<result;
	return 0;
}

/*
Input: N = 40
Output: 130
Input: N = 17
Output: 17

Time Complexity: O(1)
Space Complexity: O(1)
*/