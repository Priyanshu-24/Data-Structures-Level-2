// we have give the position of knight(ghoda) in chess and a target
// and we to reach in min no. of steps to that target position

// we can solve this using bfs approach as it can been seen as shortest path in unweighted graph

// From the starting position knight can move in 8 directions and we have to check for each direction


int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	    
	    int x1 = KnightPos[0];
	    int y1 = KnightPos[1];
	    
	    int x2 = TargetPos[0];
	    int y2 = TargetPos[1];
	    
	    if(x1==x2 && y1==y2)             // if starting and target posotions are same, lil optimization step
	    return 0;
	    
	    int a[n+1][n+1];           // visited matrix as we have coordinates of x and y
	    
	    memset(a,0,sizeof(a));
	    
	    queue<pair<int,int>> q;               // queue will store x and y coordinates
	    q.push(make_pair(x1-1,y1-1));             // -1 to make in 0-coordinates system
	    
	    
	    while(q.empty() == false)
	    {
	        auto curr = q.front();
	        int i = curr.first;
	        int j = curr.second;
	        q.pop();

	        //check if x and y lie in the matrix and then check if they are not visited
	        // if not visited then push in the queue and
	        // make them visited by adding the previous point to 1 to cal distance
	        
	        if((i+1)>=0 && (i+1)<n && (j+2)>=0 && (j+2)<n && a[i+1][j+2]==0)
	        {
	            q.push(make_pair(i+1,j+2));
	            a[i+1][j+2] = a[i][j]+1;
	        }
	        
	         if((i+1)>=0 && (i+1)<n && (j-2)>=0 && (j-2)<n && a[i+1][j-2]==0)
	        {
	            q.push(make_pair(i+1,j-2));
	            a[i+1][j-2] = a[i][j]+1;
	        }
	        
	         if((i-1)>=0 && (i-1)<n && (j+2)>=0 && (j+2)<n && a[i-1][j+2]==0)
	        {
	            q.push(make_pair(i-1,j+2));
	            a[i-1][j+2] = a[i][j]+1;
	        }
	        
	         if((i-1)>=0 && (i-1)<n && (j-2)>=0 && (j-2)<n && a[i-1][j-2]==0)
	        {
	            q.push(make_pair(i-1,j-2));
	            a[i-1][j-2] = a[i][j]+1;
	        }
	        
	         if((i+2)>=0 && (i+2)<n && (j+1)>=0 && (j+1)<n && a[i+2][j+1]==0)
	        {
	            q.push(make_pair(i+2,j+1));
	            a[i+2][j+1] = a[i][j]+1;
	        }
	        
	         if((i+2)>=0 && (i+2)<n && (j-1)>=0 && (j-1)<n && a[i+2][j-1]==0)
	        {
	            q.push(make_pair(i+2,j-1));
	            a[i+2][j-1] = a[i][j]+1;
	        }
	        
	         if((i-2)>=0 && (i-2)<n && (j+1)>=0 && (j+1)<n && a[i-2][j+1]==0)
	        {
	            q.push(make_pair(i-2,j+1));
	            a[i-2][j+1] = a[i][j]+1;
	        }
	        
	         if((i-2)>=0 && (i-2)<n && (j-1)>=0 && (j-1)<n && a[i-2][j-1]==0)
	        {
	            q.push(make_pair(i-2,j-1));
	            a[i-2][j-1] = a[i][j]+1;
	        }
	    }
	    
	    return a[x2-1][y2-1];    // return the target point in 0-coordinate system
	}

// Space and Time = O(N*N)
