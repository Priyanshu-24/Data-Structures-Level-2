// A Simple Solution is to keep an array of size k. The idea is to keep the array 
// sorted so that the k’th largest element can be found in O(1) time 
// (we just need to return first element of array if array is sorted in increasing order) 
// How to process a new element of stream? 

// For every new element in stream, check if the new element is smaller than current
// k’th largest element. If yes, then ignore it. If no, then remove the smallest element
// from array and insert new element in sorted order. Time complexity of processing a new element is O(k).


// just keep track of queue size and update our answer and queue accordingly

// Time = O(nlogk) => logk time to find kth largest element of one element
// Space = O(k)

vector<int> kthLargest(int k, int a[], int n) {
        
        vector<int> ans;
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i=0;i<n;i++)
        {
            if(q.size() < k)
            q.push(a[i]);
            
            else
            {
                if(a[i] > q.top())
                {
                    q.pop();
                    q.push(a[i]);
                }
            }
            
            if(q.size() < k)
            ans.push_back(-1);
            
            else
            ans.push_back(q.top());
            
            
        }
        
        return ans;
    }