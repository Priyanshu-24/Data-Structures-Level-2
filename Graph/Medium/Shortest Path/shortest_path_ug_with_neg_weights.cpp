// bellman-ford algorithm

// works with undirected graph with only negative weights

// it is not applicable for negative cycle as it keeps on reducing the value every time
// hence the algorithm is used to find the negative cycle or not

// just relax all the nodes exactly n-1 times 
// and if after relaxing n-1 times, if the distance is again reducing
// then negative cycle is present

int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
	    vector<int> dis(n, INT_MAX);
	    
	    dis[0] = 0;
	    
	    for(int i=1;i<=n-1;i++)
	    {
	        for(auto x : edges)
	        {
	            int u = x[0];
	            int v = x[1];
	            int weight = x[2];
	            
	            if(dis[u] != INT_MAX && dis[u] + weight < dis[v])
	            dis[v] = dis[u] + weight;
	        }
	    }
	    
	    for(auto x : edges)
	    {
	        int u = x[0];
	        int v = x[1];
	        int weight = x[2];
	            
	       if(dis[u] != INT_MAX && dis[u] + weight < dis[v])
	       return 1;
	    }
	    
	    return 0;
	    
	}

	// time  = O(V*E)
	// space = O(V)