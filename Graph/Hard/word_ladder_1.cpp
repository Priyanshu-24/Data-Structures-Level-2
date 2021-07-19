// we have to make end word from the starting word 
// we can make only one change in the starting word and all these words must be present in the given dictionary
// we can change only one char in the word 

// we will try to change each char in the starting word and check if present in dic or not
// as soon as we find a word present in dic we push it in the queue and remove it from the set

// this is a graph problem as we have to find the shortest distance in undirected graph with constant weight
// and the nodes of the graph are the words from the wordlist with adjacent node having just one letter change

int ladderLength(string start, string end, vector<string>& wordList) {
        
        unordered_set<string> word;
        
        for(int i=0;i<wordList.size();i++)      // take an unordered set to make searching operaions in constant time
            word.insert(wordList[i]);
        
        if(word.find(end)==word.end())     // if end word is not present in the dictionary
            return 0;
        
        queue<string> q;
        q.push(start);
        
        int ans = 0;            // variable to cal final length of transformation
        
        while(!q.empty())
        {
            ans++;
            
            int ql = q.size();
            
           while(ql--)
           {
               
                string pp = q.front();
                 q.pop();
            
            // now we will iterate in all char of the word and check for the tranformation
            for(int i=0;i<pp.size();i++)
            {
                char temp = pp;     // we will need this to make changes if our word is not present in the dictionary
                
                for(char j='a';j<='z';j++)
                {
                    temp[i] = j;
                    
                    if(temp==end)          // if we found the word
                        return l+1;
                    
                    if(word.find(temp)==word.end())          // if our transformation is not present in the dictionary
                        continue;
                    
                    // if the code reaches here then our transformed word is present in the dic and we will push our word to the queue
                    //and erase it from the set as we can use one word only once
                    word.erase(temp);
                    q.push(temp);
                }
                
            }
           }
        }
        
        return 0;
    }

// time = O(N^2 * M) or O(N^2 * M * 26)
// N = size of word, M = no of words in the list
// space = O(N*M)