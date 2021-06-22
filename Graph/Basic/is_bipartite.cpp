// bipartite graph is a graph in which we can color each of the two adjacent nodes by using two
// different colors.

// here we will do dfs and in dfs if any call will return false we will return false as an answer

// in dfs first we will color the node with color = 1
// and then while calling for its adjacant nodes we will check 
// if the node is not colored then color it with opposite color
// and if it is colored then check if the color is same as the previous node or not

// here we will take a color array instead of visited array

bool bipartite_dfs(int node, vector<int> adj[], vector<int> &color)
   {
       if(color[node] == -1)
       color[node] = 1;
       
       for(auto it : adj[node])
       {
           if(color[it] == -1)
           {
               color[it] = 1 - color[node];
               
               if(!bipartite_dfs(it, adj, color))
               return false;
           }
           
           else if(color[it] == color[node])
           return false;
       }
       
       return true;
       
   }

	bool isBipartite(int V, vector<int>adj[]){
	    
	    vector<int> color(V, -1);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(color[i] == -1)
	        {
	            if(!bipartite_dfs(i, adj, color))     // we can also use bipartite_bfs
	            return false;
	        }
	    }
	    
	    return true;
	    
	}

	// we can also do it using bfs

	bool bipartite_bfs(int src, vector<int> adj, vector<int> &color)
	{
		color[src] = 1;
		queue<int> q;

		q.push(src);

		while(!q.empty())
		{
			int node = q.front();
			q.pop();

			for(auto it : adj[node])
			{
				if(color[it] == -1)
				{
					color[it] = 1 - color[node]; 
					q.push(it);
				}

				else if(color[it] == color[node])
					return false;
			}
		}

		return true;
	}

	// time  = O(V+E)
	// space = O(V+E)