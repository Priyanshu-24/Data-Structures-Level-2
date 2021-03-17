 void dfs(int i,int j,vector<vector<int>> &vis, vector<vector<int>> &image, int n, int m, int oc, int nc)
    {
        if(i<0 or j<0 or i>=n or j>=m)
            return;
        
        if(vis[i][j] or image[i][j]!=oc)
            return;
        
        image[i][j] = nc;
        vis[i][j] = 1;
        
        dfs(i+1,j,vis,image,n,m,oc,nc);
        dfs(i,j+1,vis,image,n,m,oc,nc);
        dfs(i,j-1,vis,image,n,m,oc,nc);
        dfs(i-1,j,vis,image,n,m,oc,nc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int x = image.size();
        int y = image[0].size();
        
        vector<vector<int>> vis(x,vector<int>(y,0));
        
        int oldColor = image[sr][sc];
        
        dfs(sr,sc,vis,image,x,y,oldColor,newColor);
        return image;
        
    }