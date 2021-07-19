// we have to find the no islands
// islands are group with 1
// 1 = island, 0 = water
// just traverse the whole matrix using dfs and increase the count as we encounter another island

// as soon as we encounter a 1 we mark it as visited as a part a island part so that in next iteration 
// it will not be counted

void dfs(int i,int j,vector<vector<int>> &vis,int n,int m,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m)
        return;
        
        if(grid[i][j]=='0')
        return;
        
        if(vis[i][j]==0)              // if we reach here then we have 1
        {
            vis[i][j]=1;
            
            dfs(i+1,j,vis,n,m,grid);
            dfs(i-1,j,vis,n,m,grid);
            dfs(i+1,j+1,vis,n,m,grid);
            dfs(i,j+1,vis,n,m,grid);
            dfs(i,j-1,vis,n,m,grid);
            dfs(i-1,j+1,vis,n,m,grid);
            dfs(i-1,j-1,vis,n,m,grid);
            dfs(i+1,j-1,vis,n,m,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        
        
        vector<vector<int>> vis( n , vector<int> (m, 0));     // visited vector
        
        int count=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0 && grid[i][j]=='1')
                 {
                    dfs(i,j,vis,n,m,grid);
                    count++;
                 }
            }
        }
        
        return count;
    }

 // In gfg we have to check 8 sides i.e. digonally too, whereas in leetcode we just have to check in 4 directions   
 // Time and Space = O(n*m) or O(row*column)