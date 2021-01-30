// Can be easily done with inorder traversal
// Time : O(n)   Space : O(h)
// we can also do it in O(1) space using morris traversal which does inorder traversal without using stack and recursion

 int ans = -1;
    
    void inorder(TreeNode* root,int &k)
    {
        if(!root)
            return;
        
        if(ans!=-1)
            return;
        
        inorder(root->left,k);
        
        k--;
        if(k==0)
            ans = root->val;
        
        inorder(root->right,k);

            
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root,k);
        
        return ans;
        
    }

// we can optimize time by modifying BST structure by adding a new integer in the BST class or structure    