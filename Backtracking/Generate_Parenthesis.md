
Given an integer n representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses..
(HARD)

	INPUT FORMAT :

The first and only line of input will take an integer n representing number of pairs of parenthesis.

OUTPUT FORMAT : 

Display all possible combinations of parentheses in a new line.
CONSTRAINTS :
	1 <= n <= 8
EXAMPLE :
	Input : n = 3   
Output : ((()))
(()())
(())()
()(())
()()()
Explanation :
The opening brackets can be placed if n > 0 and the opening brackets can be placed till the closing brackets remain less than or equal to n. There are only five sequences of balanced parenthesis formed using 3 pairs of balanced parenthesis.
