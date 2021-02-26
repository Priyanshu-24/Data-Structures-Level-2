// We will make root the first element 
// if low == high , then return root
// Or find the first element greater than root (i) and recur on left side from idx to i-1 and on right side from i to high    

   TreeNode* solve(vector<int> &a, int &idx, int low, int high, int n)
    {
       if(idx >= n || low > high)         // imp base condition
           return NULL;
         
         TreeNode* root = new TreeNode(a[idx++]);       // make root and increase idx
         
         if(low == high)       // if the subtree contains only one child no need to recur
             return root;         // reduces efficency by more than 50%
         
         
         int i;             // index to find next greater element than root         
         
         for(i=low;i<=high;i++)
             if(a[i] > root->val)
                 break;
         
         root->left = solve(a,idx,idx,i-1,n);           
         root->right = solve(a,idx,i,high,n);
         
         return root;        
         
    }
    
    TreeNode* bstFromPreorder(vector<int>& a) {
        
         int idx = 0;
        
        return solve(a,idx,0,a.size()-1,a.size());
        
    }

// The above method takes O(n^2) time 

// We can reduce time complexity to O(n) by setting range for each element and if the element 
// comes in the range than only we will create node

 TreeNode* solve(vector<int>&a, int &idx, int low, int high, int key)
    {
        if(idx >= a.size())
            return NULL;
        
        TreeNode* root = NULL;         // imp step, always initialize to NULL
        
        if(key > low && key < high)
        {
            root = new TreeNode(key);
            
            idx++;             // don't forget this
            

            // check both times
            if(idx < a.size())
                root->left = solve(a,idx,low,key,a[idx]);
            
            if(idx < a.size())
                root->right = solve(a,idx,key,high,a[idx]);
        }
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& a) {
        
        int idx = 0;
        
        return solve(a,idx,INT_MIN,INT_MAX,a[0]);
        
    }    

// the only thing to take care of low and high parameters
// and do not forget to increment idx    