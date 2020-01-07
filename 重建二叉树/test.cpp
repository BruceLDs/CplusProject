#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in)
{
	if (pre.size() == NULL)
		return NULL;
	TreeNode* root = new TreeNode(pre[0]);
	int i;
	for (i = 0; i != in.size() && in[i] != pre[0]; i++);
	vector<int> pre_left, in_left, pre_right, in_right;
	int pre_i = 1;
	for (int j = 0; j != in.size(); j++)
	{
		if (j < i)
		{
			in_left.push_back(in[j]);
			pre_left.push_back(pre[pre_i]);
			pre_i++;
		}
		else if (j>i)
		{
			in_right.push_back(in[j]);
			pre_right.push_back(pre[pre_i]);
			pre_i++;
		}
	}
	root->left = reConstructBinaryTree(pre_left, in_left);
	root->right = reConstructBinaryTree(pre_right, in_right);
	return root;
}

int main()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> in = { 4, 7, 2, 1, 5, 3, 8, 6 };
	TreeNode* root = reConstructBinaryTree(pre, in);
	return 0;
}