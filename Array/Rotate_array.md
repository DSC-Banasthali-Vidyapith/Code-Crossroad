Given an unsorted array arr[] of size N, rotate it by D elements in the counter-clockwise direction. 

**Input:**  N = 5, D = 2  
            arr[] = {1,2,3,4,5}
**Output:** 3 4 5 1 2
**Explanation:** 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.

**Input:**  N = 10, D = 3
            arr[] = {2,4,6,8,10,12,14,16,18,20}
**Output:** 8 10 12 14 16 18 20 2 4 6
**Explanation:** 2 4 6 8 10 12 14 16 18 20 when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

**Expected Time Complexity:** O(N)
**Expected Auxiliary Space:** O(1)

Constraints:
1 <= N <= 10^7
1 <= D <= N
0 <= arr <= 10^5

### DIFFICULTY LEVEL : EASY
### ASKED BY : Microsoft , Amazon
