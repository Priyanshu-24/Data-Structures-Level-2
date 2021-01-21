// If we are given inorder traversal then we can easily contruct a tree as its middle element is root and elements 
// to its left are left children and elements on right are right children.

// take starting and ending index of the inorder as parameter.

// Now the first element of preorder traversal is root element, so we use preorder traversal to only decide the root elment
// Take a global index to make roots from preorder traversal

// After we get the root from preorder, we search that element in the inorder and calculate the index of the root
// Now all elements to its left and right are left and right children of thr root

// And at the end make the left and right child of the root using the index of root from the inorder traversal


  int idx = 0;
    
    TreeNode* build(vector<int> &preorder, vector<int>&inorder, int s, int e)
    {
        if(s > e)               //base condition
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);          // make root and increase the index value for next root
        
        if(s==e)              // if root is leaf node.....then return from here only
            return root;
        
        int x;
        
        for(int i = s;i<=e;i++)                // searching for the index of root in inorder traversal
        {
            if(inorder[i] == root->val)
            {
                x = i;
                break;
            }
        }
        
        // make left and right child of the root
        root->left = build(preorder,inorder,s,x-1); 
        root->right = build(preorder,inorder,x+1,e);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return build(preorder, inorder, 0, inorder.size()-1);
        
    }

// The above method takes O(n^2) time in worst case
    // We can reduce it to O(n) by using a unordered_map to store the index of each element so that
    // we will neglect searching for the index each time


  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] = i;
        
        idx = inorder.size()-1;
        return build(inorder,postorder, 0, inorder.size()-1, m);
        
    }  // and x = m[root->data] int build method
..................................................................................................................
//Note :- Always pass the referance of the vectors and map which will reduce the time complexity to a great extent
..................................................................................................................       
