// solution is same as merge k sorted arrays

// here we have to add a comapre function for linked list as the priority_queue is of the type ListNode

// Time = O(Nlogk) ans Space = O(k) , N = total no of elements in all the lists
class Solution {
public:
    
    struct compare{
        bool operator() (ListNode* a, ListNode*b)
        {
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        
        for(auto x : lists)
            if(x)               // checking if there is NULL node
              q.push(x);
        
        if(q.empty())
            return NULL;
        
        ListNode * curr = NULL;
        ListNode* ans = NULL;
        
        while(!q.empty())
        {
            ListNode* temp = q.top();
            q.pop();
            
            cout<<temp->val<<" ";
            
            if(curr == NULL)    // for first node
                ans = temp;
            
            else
                curr->next = temp;
            
            curr = temp;
            
            if(curr->next)
                q.push(curr->next);
                      
        }
        
        return ans;
        
    }
};