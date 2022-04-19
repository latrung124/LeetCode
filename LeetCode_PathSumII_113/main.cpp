#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<vector<int>> m_result;
public:
	void sum(TreeNode* root, int targetSum, vector<int> path) {
		if (root == nullptr) return;
		path.push_back(root->val);
		if (root->left != nullptr) {
			sum(root->left, targetSum, path);
			path.push_back(root->left->val);
		}
		if (root->right != nullptr) {
			if (root->left != nullptr)
				path.pop_back();
			sum(root->right, targetSum, path);
			path.push_back(root->right->val);
		}
		if (root->left == nullptr && root->right == nullptr) {
			int sum = 0;
			for (auto& i : path) {
				sum += i;
			}
			if (sum == targetSum) {
				m_result.push_back(path);
			}
		}
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		vector<int> path;
		sum(root, targetSum, path);
		return m_result;
	}
};

int main() {
	cout << "LeetCode_PathSumII_113" << endl;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	root->right->right->right = new TreeNode(6);
	Solution s;
	s.pathSum(root, 7);
	for (int i = 0; i < s.m_result.size(); i++) {
		for (int j = 0; j < s.m_result.at(i).size(); j++) {
			cout << s.m_result.at(i).at(j) << " " << endl;
		}
		cout << endl;
	}
	return 0;
}