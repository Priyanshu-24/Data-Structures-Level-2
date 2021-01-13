// Solution for leetcode

 vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(q.size())
        {
            vector<int> temp;
            int n = q.size();
            
            while(n--)
            {
                TreeNode * pp = q.front();
                q.pop();
                temp.push_back(pp->val);
                
                if(pp->left)
                    q.push(pp->left);
                
                if(pp->right)
                    q.push(pp->right);
            }
            
            ans.push_back(temp);
        }
        
        reverse(ans.begin(), ans.end());                //just reverse the matrix of level order
        
        return ans;
           
    }


// For geeksforgeeks : print in single line

// First add the right child in the queue then left child and then reverse the array in the end ...:)    