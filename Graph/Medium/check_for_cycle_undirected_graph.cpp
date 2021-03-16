 // first method is using dfs 
// just same like directed graph just a cache here is that we have to check for the parent instead of 
// recursive stack what we do in directed graph
// if the current node is not equal to parent then cycle exists

 bool dfs(int src, vector<int> &vis, vector<int> adj[], int p)
    {
        vis[src] = 1;
        
        for(auto x : adj[src])
        {
            if(vis[x] == 0)
            {
                if(dfs(x,vis,adj,src))
                   return true;
            }
            
            else if(x!=p)          // check if not parent then return true
               return true;
        }
        
        return false;
    }

	bool isCycle(int V, vector<int>adj[]){
	    
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i<V ; i++)
	    {
	        if(vis[i] == 0)
	        {
	            if(dfs(i,vis,adj,-1))             // parent for the first node will be -1
	                return true;
	            
	        }
	    }
	    
	    return false;
	}



// second method is by using bfs 
// in this make a parent vector and initialize all as -1
// then return true if the parent of node not equal to its connection	



 bool bfs(int src, vector<int> &vis, vector<int> adj[], int V)
    {
       queue<int> q;
       
       vector<int> p(V,-1);           // parent vector
       
       q.push(src);
       vis[src] = 1;
       
       while(!q.empty())
       {
           int temp = q.front();
           q.pop();
           
           for(auto x : adj[temp])
           {
               if(vis[x] == 0)
               {
                   vis[x] = 1;
                   q.push(x);
                   p[x] = temp;          // make parent
               }
               
               else if(p[temp]!=x)
                 return true;
           }
           
       }
       
       return false;
    }

	bool isCycle(int V, vector<int>adj[]){
	    
	    vector<int> vis(V,0);
	    
	    for(int i = 0; i<V ; i++)
	    {
	        if(vis[i] == 0)
	        {
	            if(bfs(i,vis,adj,V))
	                return true;
	            
	        }
	    }
	    
	    return false;
	}

