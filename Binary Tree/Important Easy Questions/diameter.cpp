// Longest distance b/w any two nodes
// The path may or may not be through the root node


//Basic Solution :-
// calculate left and right height ( by making height function )
// calculate left and right diameter ( by recursively calling the same diameter function )
// return max ( lh+rh+1, max(ld,rd))

// But this method takes O(n^2) time as one iteration is for height and another is for diameter


// Efficient method :-

// calculate diameter in the same height function
// O(n) time

int height(TreeNode*root, int &ans)
    {
        if(root==NULL)
            return 0;
        
        int l = height(root->left, ans);
        int r = height(root->right, ans);
        
        ans = max(ans, l+r);                    // l+r gives no of edges (leetcode) and 1+l+r gives no of nodes (gfg)
                                               // just see in the question what is asked
        return 1+max(l,r);
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        int ans = INT_MIN;
        
        int h = height(root,ans);
        
        return ans;
        
    }