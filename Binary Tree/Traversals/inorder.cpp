 vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        stack <TreeNode*>s;
        TreeNode *curr = root;
        
        while(curr || s.empty()==false)
        {
            if(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            
            else
            {
                curr = s.top();
                s.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return ans;
        
    }