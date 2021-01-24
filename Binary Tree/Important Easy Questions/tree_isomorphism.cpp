// two trees are called isomorphic if they can be converted to each other by flipping their left and right child any number of times

// Solution :-
// if both are empty then .....true
// if one of them are empty.....false
// if the data of parents are not equal then....false
// at last check -> if tree are not flipped (i.e right and left child pf both the trees are equal) 
//                  or
//               -> if trees are flipped (i.e right child of tree1 is equivalent to left child of tree2 and vice versa)


bool flipEquiv(TreeNode* a, TreeNode* b) {
        
        if(!a and !b)
            return true;
        
        if(!a or !b)
            return 0;
        
        if(a->val != b->val)
            return 0;
        
        return (flipEquiv(a->left,b->left) and flipEquiv(a->right,b->right)) or
                (flipEquiv(a->left,b->right) and flipEquiv(a->right,b->left));
           
    }