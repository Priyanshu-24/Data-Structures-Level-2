 TreeNode* solve(vector<int> &a,int s, int e)
    {
        if(e<s)
         return NULL;
            
        int m = s+(e-s)/2;
            
            TreeNode* root = new TreeNode(a[m]);
            
            root->left = solve(a,s,m-1);
            root->right = solve(a,m+1,e);
        
        
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return solve(nums,0,nums.size()-1);
        
    }