// we are given k arrays, all in sorted order
// we have to return an array in sorted form containing all the elements of the matrix

// the basic solution is to store all elements in ana array and sort the resultant array
// Time = O(NlogN) and Space = O(N), where N = n*k i.e. all elements of the matrix

// We can do it using heap to reduce time = O(Nlogk) and Space = O(k)

// we will take a min heap and store the value and the position of first element of each array
// and then till the heap becomes empty
// store the first element of the heap to the answer
// and add the next element of that array from which the first element has been taken if the the next element exists


typedef pair<int, pair<int, int> > ppi ;    // our datatype to store the element and its position

vector<int> mergeKArrays(vector<vector<int>> a, int k)
    {
        vector<int> ans;     // our answer

        priority_queue<ppi, vector<ppi>, greater<ppi> > pq;    // make a min heap

        for(int i=0;i<k;i++)
        {
            pq.push({ a[i][0], {i,0} });            // store the first element of each array in the min heap
        }


        while(!pq.empty())
        {
        	ppi temp = pq.top();    // take first element to store in the answer
        	pq.pop();

        	ans.push_back(temp.first);     // push to answer

        	int i = temp.second.first;     // take position the element
        	int j = temp.second.second;

        	if(j+1 < a[i].size())     // if more elements are present in the array 
        	{
        		ans.push({ a[i][j+1], {i, j+1} });      // push next element to temp in the heap
        	}


        }

        return ans;
    }