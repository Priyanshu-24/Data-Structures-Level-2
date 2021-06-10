#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;           // n = no of nodes/vertex
	cin >> n >> m;       // m = no of edges
	
	// declare the adjacent matrix 
	int adj[n+1][n+1];            // n+1 as 1 based indexing
	
	// take edges as input 
	for(int i = 0;i<m;i++) {
	    int u, v; 
	    cin >> u >> v;
	    adj[u][v] = 1; 
	    adj[v][u] = 1; 
	}
	return 0;
}

// disadvantage of this method is that if the no of nodes are very large then it is very
// hard to make a larger 2-d matrix
// taking space complexity = (n*n)