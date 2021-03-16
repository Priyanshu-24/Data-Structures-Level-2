vector<int> ans;

void solve(int v, vector<int> &vis, vector<int> adj[])
{
    ans.push_back(v);
    vis[v] = 1;
    
    for(auto x:adj[v])      // check for each nodes connection
    {
        if(vis[x]==0)
        solve(x,vis,adj);
    }
    

}

	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    
	  //  ans.clear();
	    
	    vector<int> vis(V,0);   // visited vector
	    
	    solve(0,vis,adj);
	    
	    return ans;
	}