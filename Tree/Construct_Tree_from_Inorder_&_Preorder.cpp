/*
Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 

Input:
First line consists of T test cases. First line of every test case consists of N , denoting the number of elements in array. Second and Third line of every test case consists of Inorder and preOrder traversal of a tree.

Output:
Single line output, return the Node of the tree.

**Use already defined preIndex in template

Constraints:
1<=T<=500
1<=N<=1000

Example:
Input:
1
7
3 1 4 0 5 2 6 
0 1 3 4 2 5 6 
Output:
3 4 1 5 6 2 0
*/

#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

Node *buildTree(int a[],int b[],int str,int end);
int preIndex=0;
void printPostOrder(Node *root){
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		preIndex=0;
		Node *root=NULL;
		int a[n],b[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];
		root=buildTree(a,b,0,n-1);
		printPostOrder(root);
		cout<<endl;
	}

Node* buildTree(int in[],int pre[], int inStrt, int inEnd)
{
    if(inStrt>inEnd)return NULL;
    Node * root = new Node(pre[preIndex]);
    preIndex++;
    int i;
    for(i=inStrt;i<=inEnd;i++){
        if(in[i]==root->data)break;
    }
    root->left=buildTree(in,pre,inStrt,i-1);
    root->right=buildTree(in,pre,i+1,inEnd);
    return root;
}