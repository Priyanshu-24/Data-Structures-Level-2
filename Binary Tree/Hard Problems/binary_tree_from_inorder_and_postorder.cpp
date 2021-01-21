// the solution is same as using inorder and preorder 
// the only differnce here is that the root element in the postorder is the last element



class Solution {
public:
    
    int idx;
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int s, int e, unordered_map<int,int> &m)
    {
        if(s>e)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[idx--]);
        
        if(s==e)
            return root;
        
        int x = m[root->val];
        
        root->right = build(inorder,postorder,x+1,e,m);    //refer note.......imp cache
        root->left = build(inorder,postorder,s,x-1,m);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        
        idx = inorder.size()-1;
        return build(inorder,postorder, 0, inorder.size()-1, m);
        
    }
};

..................................................................................................................
//Note :- the only cache here is that we are making (calling) the right first as we are decreasing the index here
..................................................................................................................