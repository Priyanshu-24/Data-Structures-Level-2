int areMirror(Node* a, Node* b) 
{ 
    /* Base case : Both empty */
    if (a==NULL && b==NULL) 
        return true; 
  
    // If only one is empty 
    if (a==NULL || b == NULL) 
        return false; 
  
    /* Both non-empty, compare them recursively 
     Note that in recursive calls, we pass left 
     of one tree and right of other tree */
    return  a->data == b->data && 
            areMirror(a->left, b->right) && 
            areMirror(a->right, b->left); 
} 

// we can also do it iteratively by doing inorder traversal of both the trees but...

// we will do inorder traversal of first tree and we will do reverse inorder traversal of another tree
// and check if they are equal ......then the trees are mirror of each other or symmetric