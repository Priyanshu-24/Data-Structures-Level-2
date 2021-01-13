 // Basic Idea behind level order traversal is => remove the parent, print the parent, add children (if exists)

 vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);      //push the root
        
        while(q.size())
        {
            vector<int> temp;
            int n = q.size();
            
            while(n--)               
            {
                TreeNode * pp = q.front();
                q.pop();                                     //remove
                temp.push_back(pp->val);                     //print
                
                if(pp->left)                                 //add children
                    q.push(pp->left);
                
                if(pp->right)
                    q.push(pp->right);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }

// Inner while loop is not required if answer is expected in single line    