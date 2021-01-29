// There are three cases for deletion a node BST

// 1. If the node is leaf then just delete it
// 2. If the node has only one child -> then copy the child to node and delete the child
// 3. If the node has two children (imp case)
//     -> find inorder successor of node, then copy inorder successor to the node and delete inorder successor
//           (inorder predecessor will also do the required work)


Node* ino_succ(Node* root)
{
	Node* curr = root;

	while(curr && curr->left)
		curr = curr->left;

	return curr;
}

Node* deleteNode(Node* root, int key)
{
	if(!root)
		return root;

	if(root->data > key)
		root->left = deleteNode(root->left,key);

	else if(root->data < key)
		root->right = deleteNode(root->right,key);

    // if we found the required node for deletio
    else
    {   
    	// case 1 and 2
    	if(root->left==NULL)      
    	{
    		Node* temp = root->right;
    		free(root);
    		return temp;
    	}

    	else if(root->right==NULL)
    	{
    		Node* temp = root->left;
    		free(root);
    		return temp;
    	}

    	// case 3 (node with two children)
    	
    	// find inorder successor (smallest element on right side)
    	Node *temp = ino_succ(root->right);

    	root->data = temp->data;    // copy data of inorder successor

    	root->right = deleteNode(root->right,temp->data);    // delete inorder successor
    }

    return root;
}