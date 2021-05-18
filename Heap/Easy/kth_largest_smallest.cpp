// basic method is to use sorting (nlogn)

// can be easily solved by using heap 

int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, greater<int>> mh;
        
        for(int i=0;i<nums.size();i++)
        {
            mh.push(nums[i]);
            
            if(mh.size()>k)
                mh.pop();
            
        }
        
        return mh.top();
        
    }

// all questions can be solved using this method    