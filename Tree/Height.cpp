/*
Given a binary tree, find height of it.

        1
     /     \
   10      39
  /
5
The above tree has a height of 3.
Note: Height of empty tree is considered 0.

Input:
First line of input contains the number of test cases T. For each test case, there will be only a single line of input which is a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denote node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
For each testcase, in a new line, print the height of tree.

Your Task:
You don't have to take input. Complete the function height() that takes node as parameter and returns the height. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 105
1 <= Data of a node <= 105
Sum of N over all testcases doesn't exceed 105

Example:
Input:
3
1 2 3
2 N 1 3 N
10 20 30 40 60 N N
Output:
2
3
3

Explanation:
Testcase1: The tree is
        1
     /      \
   2        3
So, the height would be 2.
Testcase2: The tree is
                           2
                              \
                               1 
                              /    
                          3
So, height would be 3.
Testcase3: The tree is

                           10
                        /        \
                     20         30
                  /       \
               40       60

So, height would be 3.
*/

int height(Node* node)
{
   // Your code here
   if(node==NULL)return 0;
   return (1+max(height(node->left),height(node->right)));
   
}