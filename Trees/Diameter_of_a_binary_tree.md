#### Problem Description

Given a Binary Tree, find the diameter of it. The diameter of a binary tree is the number of nodes on the longest path between two end nodes in the tree.

#### Input Format

Root node of the binary tree.

#### Output Format

Return a single integer denoting the diameter of the given binary tree.

### Example

Input : Root node (10) of the given tree.

```
    10
   /  \
  20  30
```

Output : 3

Explanation : The longest path between two end nodes is between node 20 and node 30 with a total distance of 3.

Input : Root node (1) of the given tree.

```
    1
   / \
  2   3
     / \
    4   6
     \
      5
     /
    7
```

Output : 6

Explanation : The longest path between two end nodes is between node 2 and node 7 with a total distance of 6.
