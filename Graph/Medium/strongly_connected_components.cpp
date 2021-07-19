// kosaraju's algorithm

// SCC are those in which we can reach from one node to all the nodes of that component
// (Obviously we have directed graph)
// scc can be merely a single node also

// the cache here is that we will do dfs in reverse order

// steps :-
// 1) sort all the nodes in order of their finishing time
// 2) transpose the graph (reverse the directed nodes)
// 3) do dfs according to finishing time

// in this question we have to return the no of scc 
// we can also use the same algo to print all the scc

void topo_dfs(int node, vector<int> &vis, vector<int> adj[],stack<int> &s)
	{
	    vis[node] = 1;
	    
	    for(auto x : adj[node])
	    {
	        if(!vis[x])
	        topo_dfs(x,vis,adj,s);
	    }
	    
	    s.push(node);
	}
	
	void rev_dfs(int node, vector<int> &vis, vector<int> transpose[])
	{
	    vis[node] = 1;
	    // print here for the node if answer is asked to print the SCC nodes
	    
	    for(auto x : transpose[node])
	    {
	        if(!vis[x])
	        rev_dfs(x,vis,transpose);
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> s;
        
        for(int i=0;i<V;i++)           // step 1
        {
            if(vis[i] == 0)
            topo_dfs(i,vis,adj,s);
        }
        
        vector<int> transpose[V];     // our tranpose graph
        
        for(int i=0;i<V;i++)               // step 2
        {
            vis[i] = 0;
            
            for(auto x : adj[i])
            transpose[x].push_back(i);
        }
        
        int ans = 0;
        
        while(!s.empty())                // step 3
        {
            int node = s.top();
            s.pop();
            
            if(!vis[node])
            {
                ans++;
                rev_dfs(node,vis,transpose);
            }
        }
        
        return ans;
      
    }