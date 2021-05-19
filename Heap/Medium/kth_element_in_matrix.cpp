// we have to find out the kth smallest element in the sorted matrix

// the solution is similar to merge k sorted arrays

typedef pair<int, pair<int, int> > ppi ;


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  priority_queue<ppi, vector<ppi>, greater<ppi>> q;
   
   for(int i=0;i<n;i++)
   {
       q.push({ mat[i][0], {i,0} });
   }
   
   int ans;
   
   while(k--)
   {
       ppi temp = q.top();
       q.pop();
       
       int i = temp.second.first;
       int j = temp.second.second;
       
       ans = temp.first;
        
       if(j+1 < n)
       {
           q.push({ mat[i][j+1], {i, j+1} });
       }
   }
   
   return ans;
}

// Time = O(Nlogk) and Space = O(k)
