// Check if tree is height balanced or not
// Means the differnce b/w the left and right subtree is not more than 1 for each and every node.

// Just use height function and calculate the ans in that

bool flag;    // declare a global variable or pass reference

// flag will store our ans 
    
    int height(TreeNode* root)
    {
        if(root==NULL)
         return 0;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r) > 1)
            flag = false;
        
        return max(l,r)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        
        flag = true;
        int h = height(root);
        
        return flag;
        
    }