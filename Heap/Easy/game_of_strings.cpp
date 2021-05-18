// we have to return the minimum sum of squares of each character count after removing k characters

// The approach here is that we will remove k characters with maximum count

// this can be done using sorting easily

// but by using heap and and value of k we can reduce the complexity to O(klogn).

// here we will use max heap as we want maximum element on the top

int minValue(string s, int k){
        
        int freq[26] = {0};    // take a frequency array to count the occurenece of each character
        
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]-'a']++;             // count occurence
        }
        
        priority_queue<int> q;
        
        for(int i=0;i<26;i++)
        q.push(freq[i]);                    // push the count of each character in the max heap
        
        while(k--)          // now remove k characters
        {
            int temp = q.top();
            q.pop();  
            temp--;                   // after removing the single occurence of max count character
            q.push(temp);              // decrease its count and push it back in the heap 
        }
        
        int ans = 0;
        
        while(!q.empty())
        {
            ans += q.top()*q.top();
            q.pop();
        }
        
        return ans;
        
    }