// just calciulate the indegree of each nodes (nodes pointing towards that node)
// and add the nodes in queue whose indegree is 0
// and then take the elements from queue and add to the answer and check for their adjacent nodes
// decrease indegree of each node in every traversal

// also known as kahn's algorithm

vector<int> topo(int N, vector<int> adj[]) {

        queue<int> q; 
	    vector<int> indegree(N, 0); 

	    for(int i = 0;i<N;i++)               // calculate indegree
	    {
	        for(auto it: adj[i])
	        {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i); 
	        }
	    }

	    vector<int> topo;

	    while(!q.empty())
	    {
	        int node = q.front(); 
	        q.pop(); 

	        topo.push_back(node);

	        for(auto it : adj[node])
	        {
	            indegree[it]--;
	            
	            if(indegree[it] == 0)
	            {
	                q.push(it); 
	            }
	        }
	    }

	    return topo;
	}

	// time  = O(N+V)
	// spcae = O(N) + O(N)