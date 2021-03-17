// we have to find if we can connect each componenet or not

// no of edges = no of components-1

// we can onlt connect each component if edges are 1 less than vertices (min criteria)

// for more understanding of que visit :-
// https://leetcode.com/problems/number-of-operations-to-make-network-connected/submissions/



void dfs(int src, vector<int> &vis, vector<int> adj[])
    {
        vis[src] = 1;
        
        for(auto x:adj[src])
        {
            if(vis[x] == 0)
                dfs(x,vis,adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        
        if(m < n-1)      // no. of edges must be equal to 1 less than no of vertices 
            return -1;  
        
        vector<int> adj[n];    // make adj list
        
        
        // make the list carefully
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<int> vis(n,0);     //visited vector for graph
        
        
        // we will use dfs to cal no. of components
        
        int c = 0;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i] == 0)
            {
                c++;
                dfs(i,vis,adj);
            }
        }
        
        return c-1;
        
    }