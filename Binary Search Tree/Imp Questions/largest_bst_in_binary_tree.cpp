// The first solution is find if root is bst and if it is bst return size of the tree
// if not find the max size in left and right side

// O(n^2) time


// function to check size of BST
int size(Node* root)
{
    if(!root)
    return 0;
    
    return 1+size(root->left)+size(root->right);
}

//function to check if BST
bool isBST(Node* root, Node* l = NULL, Node* r = NULL)
{
    if(!root)
    return true;
    
    if(l!=NULL && l->data >= root->data)
    return false;
    
    if(r!=NULL && r->data <= root->data)
    return false;
    
    return isBST(root->left,l,root) && isBST(root->right,root,r);
    
}

int largestBst(Node *root)
{
	if(isBST(root))
	return size(root);
	
	return max(largestBst(root->left), largestBst(root->right));
}