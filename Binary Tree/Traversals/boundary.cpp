// firstly we will print left boundary elements
// then leaf node
// and at last we will print right boundary elements in reverse order


// fun to print left boundary
void printl(Node *root,vector<int> &pp)
{
    if(root==NULL)
    return ;
    
    if(root->left)                     //first check left then only we will check
    {
        pp.push_back(root->data);                 // push first and move afterwards
        printl(root->left,pp);
    }
    
     else if(root->right)
    {
        pp.push_back(root->data);
        printl(root->right,pp);
    }
}


// fun to print right boundary
void printr(Node *root,vector <int> &pp)
{
     if(root==NULL)
    return ;
    
    if(root->right)             //check right first
    {
        
        printr(root->right,pp);                  //first move then print as we have to print in reverse order
        pp.push_back(root->data);
    }
    
     else if(root->left)                // if right not present then only check left
    {
         printr(root->left,pp);
        pp.push_back(root->data);
       
    }
}

// inorder traversal type for checking leaf
void leaf(Node *root,vector <int>&pp)
{
    if(root==NULL)
    return;
    
    leaf(root->left,pp);
    
    if(!root->left && !root->right)
    pp.push_back(root->data);
    
    leaf(root->right,pp);
}

vector <int> printBoundary(Node *root)
{
     vector <int>pp;
     
     if(root==NULL)
     return pp;
     
     pp.push_back(root->data);
     
     printl(root->left,pp);
     
     leaf(root->left,pp);
     leaf(root->right,pp);
     
     printr(root->right,pp);
     
     return pp;
}

// Just see the variation in leaf and right boundary printing how we have to check if left present or right
// and how we are printing and moving for recursion