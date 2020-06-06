/*
Your Task:
In this function problem, the task is to complete the function modify which takes one argument: Address of the root of the BST. The function should contain the logic to modify the BST so that in the modified BST, every node has a value equal to the sum of its value in the original BST and values of all the elements larger than it in the original BST.

Expected Time Complexity: O(N)

Constraints:
1<=T<=10
1<=N<=100000

Example:
Input:
2
50 30 70 20 40 60 80
2 1 5 N N 4 7

Output:
350 330 300 260 210 150 80
19 18 16 12 7
Explanation:

              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80 

The above tree should be modified to following 

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80
*/

void modifyUtil(Node * root,int &sum){
    if(root==NULL)return;
    modifyUtil(root->right,sum);
    sum=sum+root->data;
    root->data=sum;
    modifyUtil(root->left,sum);
}
void modify(Node **root)
{
    int sum=0;
    modifyUtil(*root,sum);
}