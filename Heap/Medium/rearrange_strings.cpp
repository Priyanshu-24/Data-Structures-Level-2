// we have to check whether the string can be rearranged such that no two adjacent characters are same

// here we count the occurence of each character in a frequency array
// and store the frequency count with the character in the priority_queue (max heap)

// store the char with max count in the answer string and reduce its count
// and if its count is greater than 0, then again insert that char in the heap in next iteration by storing
// it in prev variable

string rearrangeString(string str)
    {
        int a[26] = {0};
        
        for(int i=0;i<str.size();i++)
        {
            a[str[i]-'a']++;
        }
        
        priority_queue< pair<int, char> > q;
        
        for(int i=0;i<26;i++)
        {
            if(a[i])
            q.push({ a[i], i+'a' });
        }
        
        pair<int,char> prev = {-1, '#'};
        
        string ans = "";
        
        while(!q.empty())
        {
            auto temp = q.top();
            q.pop();
            
            ans += temp.second;
            
            if(prev.first > 0)        // this step will ensure that the string length will be less than the
            q.push(prev);             // original string
            
            temp.first--;
            
            prev = temp;
            
        }
    
        if(ans.size() != str.size())
        return "-1";
        
        return ans;
        
        
    }