// take a node and check if it is not visited
// then add that node in the queue (also mark it visited) and run till queue becomes empty

// pop the first element from the queue and print that for answer

// now also add the adjacents nodes of the node

vector<int>bfsOfGraph(int V, vector<int> adj[]){

	    vector<int> bfs;    // answer

	    vector<int> vis(V, 0);   // visited vector

	    for(int i=0;i<V;i++)
	    {
	    	if(vis[i] == 0)
	    	{
	    		queue<int> q;

	    		q.push(i);
	    		vis[i] = 1;

	    		while(!q.empty())
	    		{
	    			int node = q.front();
	    			q.pop();

	    			bfs.push_back(node);

	    			for(auto it : adj[node])
	    			{
                        if(!vis[it])
                        {
                        	q.push(it);
                        	vis[it] = 1;
                        }
	    			}


	    		}
	    	}
	    }
	    
	    return bfs; 
	}

	// a node is marked visited whenever it is pushed into the queue

	// time  = O(V+E)
	// space = O(V)