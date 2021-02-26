//Inorder traversal without using recursion and stack

// Algorithm :-

// take a node curr = root and start loop
// 1. if curr->left == NULL.....then print and make curr = curr->right
// 2. else 
//        find inorder predecessor of the curr
//        2.1  if pre->right == NULL.....then pre->right == curr and curr = curr->left  
//        2.2  else  pre->right == NULL and print curr and curr = curr->right   

void morris_traversal(Node* root)
{
	if(!root)
		return;

	Node* curr = root;
	Node* pre;

	while(curr)
	{
		if(cuur->left == NULL)
		{
			cout<<curr->data<<" ";
			curr = curr->right;
		}

		else
		{
			pre = curr->left;

			while(pre->right != NULL && pre->right != curr)           // finding inorder predecessor
				pre = pre->right;                                     // right-most element in left side

            
            if(pre->right == NULL)
            {
            	pre->right = curr;          // connect the right to curr
            	curr = curr->left;          // pass the command to left of curr
            }

            else
            {
                pre->right = NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
		}
	}
}