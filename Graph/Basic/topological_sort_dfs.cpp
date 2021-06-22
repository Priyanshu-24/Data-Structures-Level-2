// topological sort is always performed in directed ascylic graph (DAG)

// it states that if we have a edge from u->v, then
// u must appear before v in the ordering

// here we will use dfs and a stack 
// stack is used because recursive call of child node ends before the parent and then we will add
// the node in the stack after the recursive call
// so child will be added first in the stack, and as result we will get parent first in our answer


void topo_sort_dfs(int node, stack<int> &s, vector<int> adj[], vector<int> &vis)
{
	vis[node] = 1;

	for(auto it : adj[node])
	{
		if(!vis[it])
			topo_sort_dfs(it,s,adj,vis);
	}

	s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
	stack<int> s;
	vector<int> vis(V, 0);

	for(int i=0;i<V;i++)
	{
		if(vis[i] == 0)
		{
			topo_sort_dfs(i,s,adj,vis);
		}
	}

	vector<int> ans;

	while(!s.empty())
	{
		ans.push_back(s.top());
		s.pop();
	}

	return ans;
}

// time = O(V+E)
// space = O(V) + O(V)