// parent node will be the sum of its right and left child
// and leaf nodes will become zero.

int solve(Node *root)
{
	if(!root)
		return 0;      //leaf nodes will become 0 here

	int l = solve(root->left);
	int r = solve(root->right);
	int old = root->data;      // to store the curr node data to return it to its parent as its value will be changed

	root->data = l+r;            //change the curr node data

	return l+r+old;         // return value for curr node parent as sum of its left and right + the node data
}

void tosum(Node *root)
{
	solve(root);
}