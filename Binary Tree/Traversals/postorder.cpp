 vector<int> postorderTraversal(TreeNode* root) {
        
        vector <int>ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> s1;
        
        s1.push(root);
        
        while(!s1.empty())
        {
            TreeNode* temp = s1.top();
            s1.pop();
            
            ans.push_back(temp->val);
            
            if(temp->left)
                s1.push(temp->left);
            
            if(temp->right)
                s1.push(temp->right);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }