// The nodes of DLL must be in inorder traversal of binary tree.
// The right pointer is next pointer and left is prev pointer.

// Just do the inorder traversal and make the first node as head
// And then then keep track of nodes using a prev pointer


//make sure to pass as refernce to change the value
void solve(Node *root, Node *&head, Node *&prev, bool &flag)
{
    if(!root)
    return;
    
    solve(root->left,head,prev,flag);
    if(flag)
    {
        head = root;
        prev = root;
        flag = false;
    }
    
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    
    solve(root->right,head,prev,flag);
}

Node * bToDLL(Node *root)
{
    if(root==NULL)
    return root;
    
    Node *head = NULL;
    Node *prev = NULL;
    bool flag = true;
    
    solve(root,head,prev,flag);
    
    return head;
}
