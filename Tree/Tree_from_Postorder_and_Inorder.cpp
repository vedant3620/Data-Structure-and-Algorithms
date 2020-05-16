/*
int postIn;

Node * buildUtil(int in[], int post[],int ins,int ine){
    if(ins>ine)return NULL;
    Node * root=new Node(post[postIn--]);
    int i;
    for(i=ins;i<=ine;i++){
        if(in[i]==root->data)break;
    }
    root->right=buildUtil(in,post,i+1,ine);
    root->left=buildUtil(in,post,ins,i-1);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    postIn=n-1;
    return buildUtil(in,post,0,n-1);
}
*/

int postIn;

Node * buildUtil(int in[], int post[],int ins,int ine){
    if(ins>ine)return NULL;
    Node * root=new Node(post[postIn--]);
    int i;
    for(i=ins;i<=ine;i++){
        if(in[i]==root->data)break;
    }
    root->right=buildUtil(in,post,i+1,ine);
    root->left=buildUtil(in,post,ins,i-1);
    return root;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    postIn=n-1;
    return buildUtil(in,post,0,n-1);
}