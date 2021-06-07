A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j  is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
Note: Follow 0 based indexing.
 
Example 1:
Input:
N = 3
M[][] = {{0 1 0},
         {0 0 0}, 
         {0 1 0}}
Output: 1

Explanation: 0th and 2nd person both
know 1. Therefore, 1 is the celebrity.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
Constraints:
2 <= N <= 3000
0 <= M[][] <= 1


### DIFFICULTY LEVEL : EASY
### ASKED BY : Oracle, Walmart, Amazon
