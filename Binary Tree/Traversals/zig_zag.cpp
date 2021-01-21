// zig zag level order traversal

 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        
        if(!root)
            return ans;
        
        bool flag = true;
        
        queue <TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            vector<int> a;
            
            while(n--)
            {
                TreeNode* t = q.front();
                q.pop();
                
                a.push_back(t->val);
                
                if(t->left)
                    q.push(t->left);
                
                if(t->right)
                    q.push(t->right);
            }
            
            if(flag==false)
                reverse(a.begin(),a.end());
            
            ans.push_back(a);
            
            flag=!flag;
        }
        
        
        
        return ans;
        
    }

// can also be done using two stacks


vector <int> zigZagTraversal(Node* root)
{
    
    vector <int>pp;
    
	if(root==NULL)
	return pp;
	
	stack <Node*>c;
	stack <Node*>n;
	
	bool flag=true;      // true for left to right traversal
	
	c.push(root);
	
	while(c.empty()==false)
	{
	    Node *temp=c.top();
	    c.pop();
	    
	    if(temp)
	    {
	        pp.push_back(temp->data);
	        
	        if(flag)
	        {
	            if(temp->left!=NULL)
	            n.push(temp->left);
	            
	            if(temp->right!=NULL)
	            n.push(temp->right);
	        }
	        
	        else{
	            if(temp->right!=NULL)
	            n.push(temp->right);
	            
	            if(temp->left!=NULL)
	            n.push(temp->left);
	        }
	    }
	    
	    if(c.empty())                 // don't forget to swap whwn current stack becomes empty
	    {
	        flag=!flag;
	        swap(n,c);
	    }
	}
	
	return pp;

}	  

// solution depends how it has asked to return, whereas in this question we can do it easily with a queue 