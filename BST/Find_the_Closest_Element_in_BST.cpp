/*
Given a BST with N nodes and a target node K. The task is to find an integer having minimum absolute difference with given target value K and return this difference.

Input Format:
The first line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:
 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Second-line is an integer represents K

Output Format:
The output for each test case will be the minimum absolute difference of a node with a given target value K.

Your Task:
This is a function problem. You don't have to take any input. Just complete the function maxDiff() that takes node and K as a parameter and returns the minimum difference.

Constraints:
1 <= T <= 10
1 <= N <= 100000

Example:
Input:
2
10 2 11 1 5 N N N N 3 6 N 4
13
8 1 9 N 4 N 10 3
9

Output:
2
0
*/

int maxDiff(Node *root, int k)
{
    if(root==NULL)return INT_MAX;
    if(root->data==k)return 0;
    if(root->data<k){
        int m=maxDiff(root->right,k);
        return min(m,k-root->data);
    }
    int m=maxDiff(root->left,k);
    return min(m,root->data-k);
}