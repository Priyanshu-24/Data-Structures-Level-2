// using level order traversal
// we will push root in the q and keep moving to its right and print the elements and stop when the node->right==NULL

// while moving to right we will also check if left child of the curr node is present then we will push it to the q
// for next digonal print


vector<int> diagonal(Node *root)
{
   vector<int> ans;
   
   if(!root)
   return ans;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       Node *temp = q.front();
       q.pop();
       
       while(temp)
       {
           if(temp->left)               //if left exists, push into q for next digonal
           q.push(temp->left);
           
           ans.push_back(temp->data);     // printing current node data
           
           temp=temp->right;         // moving to right for digonal
       }
   }
   
   return ans;
}