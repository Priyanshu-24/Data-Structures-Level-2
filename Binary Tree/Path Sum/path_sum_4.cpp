 int pathSum(TreeNode* root, int sum) {
       
       vector<vector<int>>ans;
       vector<int>res;

        if(root==NULL)
            return 0;
        
        solve(root,sum,ans,res);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        
        return ans;
        
    }

// just refer path sum 2 and path sum 3 and just add the members in the vector res and ans like done in previous questions    