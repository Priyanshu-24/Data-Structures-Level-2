bool isValidBST(TreeNode* root, TreeNode* l = NULL, TreeNode* r = NULL) {
        
        if(!root)
            return true;
        
        if(l!=NULL && root->val <= l->val)
            return 0;
        
        if(r!=NULL && root->val >= r->val)
            return 0;
        
        return isValidBST(root->left,l,root) && isValidBST(root->right,root,r);
        
    }

 // we can also do it using inorder traversal
 
 bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    // traverse the tree in inorder fashion and  
    // keep track of prev node 
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
   
        // Allows only distinct valued nodes  
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
} 
  
bool isBST(Node *root) 
{ 
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
}    