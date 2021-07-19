 // here we have given sorted order of words and we need to tell the order of letters according to that 
// sorted order dictionary

// the whole idea here is to make a graph by using the ordering of words
// if a < b then we will have a->b node in our graph
// just check for two words and if we encounter different letters then make a node of graph accordingly

// atlast perform topological sorting of that graph 

 void topo_dfs(int node, vector<int> adj[], vector<int> &vis, string &ans)
    {
        vis[node] = 1;
        
        for(auto it : adj[node])
        {
            if(!vis[it])
            topo(it,adj,vis,ans);
        }
        
        char c = node + 'a';
        
        ans = c + ans;                 // we are adding in the back of the answer
    }
    
    string findOrder(string dict[], int n, int k) {
         
         vector<int> adj[k];             // no of nodes in graph = no of letters
         
         for(int i=0;i<n-1;i++)           // making graph
         {
             string s1 = dict[i];
             string s2 = dict[i+1];
             
             for(int j=0;j<min(s1.size(), s2.size());j++)            // compare two words
             {
                 if(s1[j]!=s2[j])
                 {
                   adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                   break;
                 }
             }
         }
         
         vector<int> vis(k,0);
         string ans;
         
         for(int i=0;i<k;i++)        // do topo sort
         {
             if(!vis[i])
             topo_dfs(i,adj,vis,ans);
         }
         
         return ans;
    }

    // time  = O(N+K) 
    // space = O(K)