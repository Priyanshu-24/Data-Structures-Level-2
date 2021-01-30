void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

if(root==NULL)
return;

if(root->key==key)
{
    if(root->left)
    {
        struct Node *x = root->left;
        
        while(x && x->right)
        x=x->right;
        
        pre=x;
    }
    
     if(root->right)
    {
        struct Node *x=root->right;
        
        while(x && x->left)
        x=x->left;
        
        suc=x;
    }
}

else if(root->key > key)
{
    suc=root;
    findPreSuc(root->left,pre,suc,key);
    
}

else
{
    pre=root;
    findPreSuc(root->right,pre,suc,key);
}

}