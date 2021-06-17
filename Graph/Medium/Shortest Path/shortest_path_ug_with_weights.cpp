// dijkstra's algorithm

// just take a priority queue instead of queue to take the smallest distance in the top

// in adj 0-index = edge and 1-index = weight b/w the two nodes

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        vector<int> dis(V, INT_MAX);

        dis[s] = 0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        q.push({0,s});
        
        while(!q.empty())
        {
            int node = q.top().second;
            q.pop();
            
            for(auto it : adj[node])
            {
                if(dis[it[0]] > dis[node] + it[1])      // the only thing to take care in this question
                {                                        // just draw on paper and do it ....
                    dis[it[0]] = dis[node] + it[1];
                    q.push({dis[it[0]], it[0]});
                }
            }
        }
        
        return dis;
        
        
    }