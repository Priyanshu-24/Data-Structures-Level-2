// count number of paths with given sum
// path maynot pass start and end at root, it can be from any node to another


int count = 0;
    
    void solve(TreeNode* root,int sum)
    {
        
        if(root==NULL)
            return;
        
        sum-=root->val;
        
        if(sum==0)
            count++;
        
        if(root->left)
            solve(root->left,sum);
        
       if(root->right)
            solve(root->right,sum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        
        if(root==NULL)
            return 0;
        
        solve(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        
        return count;
        
    }