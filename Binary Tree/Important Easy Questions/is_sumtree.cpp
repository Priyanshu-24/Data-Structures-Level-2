int sum(Node *root)
{
    if(root==NULL)return 0;
    
    return root->data+sum(root->left)+sum(root->right);
}

bool isSumTree(Node* root)
{
     if(root==NULL)
     return 1;
     
     if(root->left==NULL && root->right==NULL)
     return 1;
     
     int l=sum(root->left);
     int r=sum(root->right);
     
     if(root->data==l+r && isSumTree(root->left) && isSumTree(root->right))
     return 1;
     
     return 0;
}


// O(n^2) time in worst case

// optimized version

bool flag = true;            // if subtree true

int solve(Node *root)
{
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return root->data;

    if(flag==false)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    if(root->data != l+r)
        flag = false;

    return l+r+root->data;
}

bool isSumTree(Node *root)
{
    if(!root)
        return 1;

    solve(root);

    return flag;
}