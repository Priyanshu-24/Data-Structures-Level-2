// Easy solution is to do level order traversal and print last element of each level


// Recursive solution

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

	solve(root->right, level+1, max_level, ans);       //just change the order to print first element from right side
	solve(root->left, level+1, max_level, ans);
}

vector<int> right_view(Node* root)
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