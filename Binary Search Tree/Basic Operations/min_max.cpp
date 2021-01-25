//min value

int minValue(Node* root)
{
     Node *pp=root;
    
    while(pp->left)
    pp=pp->left;
    
    return pp->data;   
}

// max value

int maxValue(Node* root)
{
    Node *pp=root;
    
    while(pp->right)
    pp=pp->right;
    
    return pp->data;
    
}