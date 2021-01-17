// The very basic and efficient solution is to do level order traversal
// And print the first element of each node
// time : O(n)   space : O(n)

// But we can do it easily with recursion too
// Just keep track current level and print the first element of each level update the level

void solve(Node* root, int level, int &max_level, vector<int>&ans)
{
	if (root==NULL)
	{
        return;
	}

	if(level > max_level)                  // if the element is first element of a particular node then print it and
	{                                      // change max level till now to current level   
		ans.push_back(root->data);
		max_level = level;
	}

	solve(root->left, level+1, max_level, ans);
	solve(root->right, level+1, max_level, ans);
}

vector<int> left_view(Node* root)
{

   vector<int> ans;

	if(root==NULL)
		return ans;

	int max_level = 0;           //this variable is for max level till now

	solve(root, 1, max_level, ans);

	return ans;
}

// Time : O(n)
// Space : O(n) due to recursive function call