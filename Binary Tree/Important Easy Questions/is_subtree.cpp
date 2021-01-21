// Check if S is a subtree of T or not


bool iden(Node *a,Node *b)
{
    if(a==NULL && b==NULL)
    return 1;
    
    if(a==NULL || b==NULL)
    return 0;
    
    return a->data==b->data && iden(a->left,b->left) && iden(a->right,b->right);
}

bool isSubTree(Node* T, Node* S) {
    
    if(S==NULL)
    return 1;
    
    if(T==NULL)
    return 0;
    
    if(iden(T,S))
    return 1;
    
    return isSubTree(T->left,S) || isSubTree(T->right,S);
    
}