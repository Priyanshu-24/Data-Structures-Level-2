// given n ropes where a[i] = length of i^th rope
// we need to connect all ropes into a single rope
// cost of connecting two ropes = length of both the ropes
// we need to minimize the cost of connecting all the ropes

// firstly we need two ropes with smallest length and add them and again put them in the array
// and then again sort the array
// we need to add two smallest length ropes till all the ropes are connected to a single rope

// here we need to sort the array after each operation
// similar to huffman coding

// we will take a min heap as we need smaller elements on top
// and pop the top two elements and add them and again push their sum in the heap
// and add the result in each iteration

// a greedy approach is used


long long minCost(long long a[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<long long>> q(a,a+n);
        
        long long ans = 0;
        
        while(q.size()>1)
        {
            long long x = q.top();
            q.pop();
            long long y = q.top();
            q.pop();
        
            ans += x+y;
            q.push(x+y);
        }
        
        return ans;
        
        
    }


// Time Complexity: O(nLogn), assuming that we use a O(nLogn) sorting algorithm. 
// Note that heap operations like insert and extract take O(Logn) time.
    
// Auxiliary Complexity: O(n). 
// The space required to store the values in min heap    