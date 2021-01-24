 // print all root to leaf pathsum equal to given sum

 void solve(TreeNode* root, int sum,  vector<vector<int>> &ans, vector<int> &res)
    {
        if(!root)
            return;
        
        sum-=root->val;
        
        res.push_back(root->val);
        
        if(sum==0 && !root->left && !root->right)
            ans.push_back(res);
        
        if(root->left)
            solve(root->left,sum,ans,res);
        
        if(root->right)
        solve(root->right,sum,ans,res);
        
        res.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> ans;
        vector<int> res;
        
        solve(root,sum,ans,res);
        
        return ans;
        
    }