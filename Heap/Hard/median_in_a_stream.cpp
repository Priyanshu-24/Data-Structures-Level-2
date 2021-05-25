// brute force approach is to sort the array in every iteration 
// which can be easily done by insertion sort which is an online algorithm
// that sorts data as it appears
// Time = O(n^2)


// Efficient solution is by using heaps

// the approach used here is => after the sorting at every iteration we divide the array in two parts
// and place left most elements(smaller elements) in the max heap and right most elements in min heap

// we will take two heaps, a min heap and a max heap

// in max heap we will store the minimum elements
// in min heap we will store the maximun elements

// as when we have to take the median we can have the middle elements as 
// maximum of minimum elements and minimum of maximum elements

// during insertion we will insert in max heap when the first element comes 
// or when any smaller element comes as we want smaller elements in max heap

// otherwise insert in min heap (the maximum elements)

// balance both the heaps when the difference b/w their sizes becomes more than 1


// return median as the average of their tops when the sizes of the heaps are equal
// else return the top of heap with larger size (size cannot be greater then 1 as we are balancing the heaps)

// Time = O(nlogn) as inserting in heaps takes logn time and we are doing it n times
// Space = O(n) for heaps


    priority_queue<int> max_h;
    priority_queue< int, vector<int>, greater<int> > min_h;
    
    void insertHeap(int &x)
    {
        if(max_h.empty() || max_h.top() > x)
        max_h.push(x);
        
        else
        min_h.push(x);
        
        balanceHeaps();
        
       
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
         if(max_h.size() > min_h.size() + 1)
        {
            min_h.push(max_h.top());
            max_h.pop();
        }
        
        else if(min_h.size() > max_h.size() + 1)
        {
            max_h.push(min_h.top());
            min_h.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(min_h.size() == max_h.size())
        {
            double x = (min_h.top()+max_h.top())/2;
            
            return x;
        }
        
        else {
            return max_h.size() > min_h.size() ? max_h.top() : min_h.top();
        }
        
    }