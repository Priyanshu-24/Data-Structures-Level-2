// top view will the first element of each vertical level
// we will do level order traversal and take a queue with pair in it ....with node and horizontal distance from root

// we will take a map to store to store the horizontal distance as a key and the data of node as value

//if we encounter that particular horizontal distance first, then we will store the value in map

void topView(struct Node *root)
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
        
        if(!m[h])
        m[h] = temp->data;
        
        if(temp->left)
        q.push({temp->left,h-1});
        
        if(temp->right)
        q.push({temp->right,h+1});
    }
    
    for(auto x:m)
    cout<<x.second<<" ";
    
}
