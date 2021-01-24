 // p and q must exist in tree
// if any of p and q equals to root, then return the root
// call left and right child
// if left(l) and right(r) both exists then return root
// otherwise return l (if exists) or else r.



 TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return NULL;
        
        if(root == p || root == q)
            return root;
        
        TreeNode *l = lowestCommonAncestor(root->left,p,q);
        TreeNode *r= lowestCommonAncestor(root->right,p,q);
        
        if(l && r)
            return root;
        
        if(l)
            return l;
        
        return r;
        
    }