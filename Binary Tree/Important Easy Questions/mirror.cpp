// post order traversal type......


    TreeNode* invertTree(TreeNode* root) {
        
        if(root==NULL)
            return root;
        
        invertTree(root->left);
        invertTree(root->right);
        
        swap(root->right,root->left);
        
        return root;
        
    }


// we can also do it iteratively by using level order traversal

// just swap the left and right child in the printing step of parent    