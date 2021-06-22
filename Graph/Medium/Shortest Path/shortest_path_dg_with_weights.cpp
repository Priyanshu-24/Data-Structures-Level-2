// first find the topological sort of the graph

// now take a distance array and update its distance accordingly

void topo_sort(int node, vector<pair<int,int>> adj[], int &vis[], stack<int> &s)
{
	vis[i] = 1;

	for(auto it : adj[node])
	{
		if(!vis[it.first])
			topo_sort(it,adj,vis,s);
	}

	s.push(node);
}

void shortest_path(int src, int V, vector<pair<int,int>> adj[])
{
	int vis[V] = {0};
	stack<int> s;

	for(int i=0;i<V;i++)
	{
		if(!vis[i])
			topo_sort(i,adj,vis,s);
	}

	int dis[N] = {INT_MAX};

	dis[src] = 0;

	while(!s.empty())
	{
		int node = s.top();
		s.pop();

		if(dis[node] != INT_MAX)
		{
			for(auto it : adj[node])
			{
				if(dis[node] + it.second < dis[it.first])
					dis[it.first] = dis[node] + it.second;
			}
		}
	}
}