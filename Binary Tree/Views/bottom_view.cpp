// just see the top view first

// keep inserting the elements in map everytime for each horizontal distance
// and at last we will get our required element at the last element at a particular horizontal distance from root.

void bottomView(struct Node *root)
{
   
    map<int,int>m;
    
    queue<pair<Node*,int>>q;
    
     if(!root)
    return;
    
    q.push({root,0});
    
    while(!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        
        q.pop();
        
        m[h] = temp->data;
        
        if(temp->left)
        q.push({temp->left,h-1});
        
        if(temp->right)
        q.push({temp->right,h+1});
    }
    
    for(auto x:m)
    cout<<x.second<<" ";
    
}
