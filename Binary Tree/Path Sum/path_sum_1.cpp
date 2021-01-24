// if path sum equals to a given value is present or not
// path must be from root to leaf...........


bool hasPathSum(TreeNode* root, int sum) {
        
        if(!root)
            return 0;
        
        sum-=root->val;
        
        if(sum==0 && !root->left && !root->right)           // condition to check leaf and the path equals sum or not
            return 1;
        
        return hasPathSum(root->left,sum) || hasPathSum(root->right,sum);
        
    }