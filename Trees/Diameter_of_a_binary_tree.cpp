/*
The diameter of a binary tree will be the maximum value of (1 + leftHeight + rightHeight) for each node.
where, leftHeight : height of left subtree
       rightHeight : height of right subtree
Therefore, the diameter of the tree can be calculated with the help of height. 
A function treeHeight() would be used to keep a track of heights of left and right subtrees for each node.
This function will also compare the calculated diameters and store the maximum amongst them.
The function would have an integer return type, returning the height of the current node for which the function is called.
*/ 

#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left, *right;
    TreeNode(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

int treeHeight(TreeNode *root, int &maxDiameter)
{
    if(root == NULL)
        return 0;

    //Store height of left subtree
    int leftHeight = treeHeight(root->left, maxDiameter);

    //Store height of right subtree
    int rightHeight = treeHeight(root->right, maxDiameter);

    //Current diameter of this node would be the node itself, and the heights of its left subtree and right subtree.
    maxDiameter = max(maxDiameter, 1 + leftHeight + rightHeight);

    //return the height of current root node
    return 1 + max(leftHeight, rightHeight);
}

int diameter(TreeNode *root)
{
    int maxDiameter = INT_MIN;
    treeHeight(root, maxDiameter);
    return maxDiameter;
}

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->right = new TreeNode(4);
    cout<<"Diameter of binary tree : "<<diameter(root);
    return 0;
}

/*
Input :
    20
   /  \
  3    13
   \   /
    7 9
Output : 
Diameter of binary tree : 5

Input :
        4
       / \
      9   2
     / \   \
    3   7   8
     \      
      5   
Output : 
Diameter of binary tree : 6

Time Complexity : O(N) 
where, N : number of nodes in the tree
Space Complexity : O(h)
where, h : height of the tree
*/