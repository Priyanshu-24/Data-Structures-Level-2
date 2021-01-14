// pop parent and print it
// push right child(if exists)
// push left child(if exists)
// pushing right child first is important as LIFO in stack will print the left child

vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int>ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> s;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode *curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            
            if(curr->right)
                s.push(curr->right);
            
            
            if(curr->left)
                s.push(curr->left);
        }
        
        return ans;
        
    }