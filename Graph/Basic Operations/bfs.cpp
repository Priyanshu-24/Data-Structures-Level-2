	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	     
	     vector<int> ans;     // answer vector
	     queue<int> q;
	     vector<int> vis(V,0);    // visited vector for checking
	     
	     q.push(0);       // push 0 by default
	     vis[0] = 1;     // make it visited after pushing in the vector
	     
	     while(!q.empty())
	     {
	         int temp = q.front();
	         q.pop();
	         ans.push_back(temp);      // print the front element
	         
	         for(auto x : adj[temp])
	         {
	             if(vis[x] == 0)         // if not visited, then push it and make it visited
	             {
	                 q.push(x);
	                 vis[x] = 1;
	             }
	         }
	     }
	     
	     return ans;
	     
	}


// Time : O(V+E)
// Space : O(V)	

