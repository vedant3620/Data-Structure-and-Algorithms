/*
Given a Binary Tree of size N and an integer K. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

Input:
First line of input contains the number of test cases T. For each test case, there will be only two line of input , first line contains integer value K and second line contains a string representing the tree as described below: 

The values in the string are in the order of level order traversal of the tree where, numbers denotes node values, and a character “N” denotes NULL child.

For example:

For the above tree, the string will be: 1 2 3 N N 4 6 N 5 N N 7 N

Output:
The function should print nodes at K distance from root. Nodes should be printed from left to right. If their is no node at distance K you don't need to print anything.

Your Task:
You don't have to take input. Complete the function printKdistance() that accepts root node and k as parameter and print the value of the nodes that are at a distance k from the root.

Constraints:
1 <= T <= 100
1 <= N <= 104
0 <= K <= 30

Example:
Input:
2
0
1 3 2
3
3 2 N N 1 5 3
Output:
1
5 3

*/

void printKdistance(struct Node *root, int k)
{
  // Your code here
  if(root==NULL)return;
  if(k==0){cout<<root->data<<" ";return;}
  printKdistance(root->left,k-1);
  printKdistance(root->right,k-1);
  
}