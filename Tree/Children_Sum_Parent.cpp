/*
Given a binary tree, complete the function that returns true if the tree satisfies the following property:
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

 
For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
Return 1 if the given tree satisfies the given property else return 0.

Your Task:
This is a function problem. You need to only complete the given function isSumProperty() that returns 0 or 1. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100
1 <= Data on nodes <= 1000

Example:
Input:
2
10 10
1 4 3 5 N
Output:
1
0

Explanation:
Testcase 1: Tree is like:
            10
           /    
        10       

Here, every node is sum of its left and right child.
Testcase 2: Here , 1 is the root node and 4,3 are its node and it can be seen that sum of root node is not equal to its children
*/

int isSumProperty(Node *node)
{
    if(node==NULL)return true;
    if(node->left==NULL&&node->right==NULL)return true;
    int l,r;
    if(node->left!=NULL) l=node->left->data;
    else l=0;
    if(node->right!=NULL)r=node->right->data;
    else r=0;
    if(node->data==l+r)return (isSumProperty(node->left)&&isSumProperty(node->right));
    else return false;
}