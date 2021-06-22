// we have to find the shortest path from one source node to another
// in a graph where weights are not given or given as 1

// here we will apply simple bfs as distance b/w two adjacent nodes is 1

// we will take a distance array and initialize all distances with infinity
// and update distances while traversing the graph

void BFS(vector<int> adj[], int N, int src)
{
	queue<int> q;
	int distance[N];

	for(int i=0;i<N;i++)
		distance[i] = INT_MAX:

	distance[src] = 0;
	q.push(src);

	while(!q.empty())
	{
		int node = q.front();
		q.pop();

		for(auto it : adj[node])
		{
			if(distance[node] + 1 < distance[it])
			{
				distance[it] = distance[node] + 1;
				q.push(it);
			}
		}
	}
}