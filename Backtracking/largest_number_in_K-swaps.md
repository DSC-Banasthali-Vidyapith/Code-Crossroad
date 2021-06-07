Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.
(MEDIUM)

INPUT FORMAT :

First line of input contains K which denotes the number of swaps allowed.
The next line of input contains the string of digits.

OUTPUT FORMAT : 

Output in a single line the largest possible integer that can be formed using the entered digits.
CONSTRAINTS :
	1 <= |str| <= 30
	1 <= K <= 10
EXAMPLE :
	Input : K = 3
	str = “3435335” 
Output : 5543333
Explanation :
Since K = 3, only three swaps are allowed.
After first swap: 3435335 -> 5435333		(swap 3 with 5)
After second swap: 5435333 -> 5534333		(swap 4 with 5)
After third swap: 5534333 -> 5543333		(swap 3 with 4)
