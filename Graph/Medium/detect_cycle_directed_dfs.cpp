 // Just solved using dfs and taking an extra rec array to keep track of elements if
// they are present in recursive stack or not and use backtracking in rec while moving backward

// Run loop and check for each vectex if they are not visited before

// cycle only present if vis[i] == 1 and rec[i] == 1


 bool dfs(int src, vector<int> &vis, vector<int> &rec, vector<int> adj[])
    {
        vis[src] = 1;     // make them visited for each visiting
        rec[src] = 1;
        
        for(auto x : adj[src])           // check for source connections
        {
            if(vis[x] == 0)
            {
               if(dfs(x,vis,rec,adj))         // if not visited before then only go inside that node
                  return true;
            }
                  
            else if(rec[x] == 1)      // if the node is visited before then check if present in recursive stack or not
               return true;
        }
        
        rec[src] = 0;            // for backtracking
        
        return false;
        
        
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	
	   	vector<int> vis(V,0);
	   	vector<int> rec(V,0);
	   	
	   	for(int i = 0; i<V ; i++)
	   	{
	   	    if(vis[i] == 0)
	   	    {
	   	      if(dfs(i,vis,rec,adj))
	   	          return true;
	   	    }
	   	}
	   	
	   	return false;
	}