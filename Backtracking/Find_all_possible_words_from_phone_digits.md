Given a keypad as shown in the diagram, and an n digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.
(MEDIUM)
	INPUT FORMAT :

The first argument of input contains an integer n.
The next n lines of input each will take a single integer.

OUTPUT FORMAT : 

Print all possible combinations of the strings that can be formed with the entered digits in a new line.
CONSTRAINTS :
	1 <= n <= 10
	2 <= a[i] <= 9
EXAMPLE :
	Input : n = 3
a[i] = {‘2’, ‘3’}   
Output : ad
ae
af
bd
be
bf
cd
ce
cf
Explanation :
Each digit can represent 3-4 alphabets. For 2, the alphabets are a, b & c so, three  recursive calls will be made with alphabets a, b & c and for 3, the alphabets are d, e & f so, the output will be ad, ae & af for the recursive call with the output string. Similarly, the output for b and c will be bd, be & bf and cd, ce & cf.


