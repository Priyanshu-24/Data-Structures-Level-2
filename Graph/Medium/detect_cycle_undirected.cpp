// just do dfs and store the parent of the node
// if the the node is visited and is not a parent, then return true

bool check_cycle_dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
{
    vis[node] = 1;

    for(auto it : adj[node])
    {
    	if(vis[it] == 0)        // if not visited then do dfs
    	{
    		if(check_cycle_dfs(it, node, adj, vis))
    			return true;
    	}

    	else if(it != parent)          // if visited and not parent
    		return true;
    }

    return false;
}



bool isCycle(int V, vector<int> adj[])
{
	vector<int> vis(V, 0);   // visited array

	for(int i=0;i<V;i++)
	{
		if(!vis[i])
		{
			if(check_cycle_dfs(i, -1, adj, vis))    // check_cycle_bfs(i,adj,vis)
				return true;
		}
	}

	return false;
}



// just do bfs and use queue with a pair to check the parent(or previously visited node)

bool cycle_check_bfs(int node, vector<int> adj[], vector<int> &vis)
{
    queue<pair<int, int>> q;    // here we use a pair to also store the parent

    q.push({node, -1});
    vis[node] = 1;

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }

            else if(it != parent)
                return true;
        }

    }

    return false;
}