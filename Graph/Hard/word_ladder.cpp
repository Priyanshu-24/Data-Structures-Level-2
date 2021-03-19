// we have to make end word from the starting word 
// we can make only one change in the starting word and all these words must be present in the given dictionary
// we can change only one char in the word 

// we will try to change each char in the starting word and check if present in dic or not
// as soon as we find a word present in dic we push it in the queue and remove it from the set

int ladderLength(string start, string end, vector<string>& wordList) {
        
        unordered_set<string> word;
        
        for(int i=0;i<wordList.size();i++)      // take an unordered set to make searching operaions in constant time
            word.insert(wordList[i]);
        
        if(word.find(end)==word.end())     // if end word is not present in the dictionary
            return 0;
        
        queue<string> q;
        q.push(start);
        
        int l = 0;            // variable to cal final length of transformation
        
        while(!q.empty())
        {
            l++;
            
            int ql = q.size();
            
           for(int k=0;k<ql;k++)
           {
               
                string pp = q.front();
                 q.pop();
            
            // now we will iterate in all char of the word and check for the tranformation
            for(int i=0;i<pp.size();i++)
            {
                char backup = pp[i];        // we will need this to make changes if our word is not present in the dictionary
                
                for(char j='a';j<='z';j++)
                {
                    pp[i] = j;
                    
                    if(pp==end)          // if we found the word
                        return l+1;
                    
                    if(word.find(pp)==word.end())          // if our transformation is not present in the dictionary
                        continue;
                    
                    // if the code reaches here then our transformed word is present in the dic and we will push pp to the queue
                    //and erase it from the set
                    word.erase(pp);
                    q.push(pp);
                }
                
                pp[i] = backup;    // undo the changes
                
                
            }
           }
        }
        
        return 0;
    }