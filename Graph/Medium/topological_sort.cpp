// can be solved using simple bfs
// just find indegree of each node (how many nodes pointing the node)
// and print the once with indegree 0 and remove their edge and the indegree of the other node will decrease
 

	vector<int> topoSort(int V, vector<int> adj[]) {
	    
	    vector<int> ans;              // result vector
	    vector<int> in(V,0);      // indegree vector ...initially zero
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto x:adj[i])                   // find indegree of each node
	        in[x]++;
	    }
	    
	    queue<int> q;
	    
	    for(int i=0;i<V;i++)
	    {
	       // cout<<in[i]<<" ";
	        if(in[i]==0)                    // push elements in queue whose indegree=0
	        q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int pp = q.front();
	        q.pop();
	        ans.push_back(pp);               // print ans
	        
	        for(auto x:adj[pp])
	        {
	            in[x]--;                             // reduce indegree  
	            if(in[x]==0)        // if after reduction of the indegree it becomes 0 then also push it in the queue
	            q.push(x);
	        }
	    }
	    
	    return ans;
	}


// this can also be implemented using dfs	