/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print 0 or 1 accordingly.

Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
0 <= Data of a node <= 106

Example:
Input:
3
1 2 N N 3
10 20 30 40 60 N N
4 6 6
Output:
0
1
1
Explanation:
Testcase1: The tree is
        1
     /    
   2
      \
       3 
The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The max difference in height of left subtree and right subtree is 1. Hence balanced.
Testcase 3: The tree is 
                                      10
                        /        \
                      6          6
The maximum difference in height of left subtree and right subtree is 0. Hence balanced.


*/

bool balanceUtil(Node *root,int *h){
    
    if(root==NULL){
        *h=0;
        return true;
    }
    int lh=0,rh=0;
    bool l=balanceUtil(root->left,&lh);
    bool r=balanceUtil(root->right,&rh);
    
    if(abs(lh-rh)>1)return false;
    *h=1+max(lh,rh);
    
    return l&&r;
    
    
}
bool isBalanced(Node *root)
{
    //  Your Code here
    int h=0;
    return balanceUtil(root,&h);
}