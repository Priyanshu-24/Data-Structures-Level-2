// first find lca of both the nodes

// distance bw a and b = dis bw lca to a + dis bw lca to b

// just see how we have calculated distance from a node to its lca....tricky

Node* LCA(Node *root, int a, int b)
{
       if(!root)
       return NULL;
       
       if(root->data == a || root->data == b)
       return root;
       
       Node* l = LCA(root->left,a,b);
       Node* r = LCA(root->right,a,b);
       
       if(l && r)
       return root;
       
       if(l)
       return l;
       
       return r;
}
   
int solve(Node *root, int a)
{
      if(!root)
      return 0;
    
      if(root->data == a)
      return 1;
     
      int l = solve(root->left,a);
      int r = solve(root->right,a);
    
      if(!l && !r)
      return 0;
       
      return l+r+1;
    
}
   
int findDist(Node* root, int a, int b)
{
    
    Node* lca = LCA(root,a,b);
    
    int x = solve(lca,a);
    int y = solve(lca,b);
    
    return x+y-2;
}