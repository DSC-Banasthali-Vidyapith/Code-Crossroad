"""
Given an array arr of size N, swap the Kth element from beginning
 with Kth element from end.
 
Algorithm : - After user enters the values we will take 2 variables
pos1 and pos2. Pos1 will have index value of kth position. Pos2 will have index value of kth position
from end. We then use pop function to remove the element and insert function to swap the elements
at their respective positions.
"""
# Enter the size and value of element from user
n, k = map(int, input().split(" "))
A = list(map(int, input().split()))[:n]  # input array of size n
pos1 = k - 1
pos2 = n - k
# popping both the elements from array
first_ele = A.pop(pos1)
second_ele = A.pop(pos2-1)
A.insert(pos1, second_ele)
A.insert(pos2, first_ele)
print(A)

"""
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Testcase 1:
Input: N = 8, K = 3
        arr[] = {1, 2, 3, 4, 5, 6, 7, 8}
Output: 1 2 6 4 5 3 7 8
Explanation: Kth element from beginning is 3 and from end is 6.

Testcase 2:
Input: N = 5, K = 2
        arr[] = {5, 3, 6, 1, 2}
Output: 5 1 6 3 2
Explanation: Kth element from beginning is 3 and from end is 1.
Constraints: 1 ≤ K ≤ N ≤ 10^5
1 ≤ arr ≤ 10^3
"""
