#include <stack>
#include <utility>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        std::stack<std::pair<TreeNode*, int>> stack;
        
        stack.push({root, root->val});
        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            if (top.first) {
                if (!top.first->left && !top.first->right) {
                    if (top.second == targetSum) return true;
                } else {
                    if (top.first->left) {
                        stack.push({top.first->left, top.second + top.first->left->val});
                    }

                    if (top.first->right) {
                        stack.push({top.first->right, top.second + top.first->right->val});
                    }
                }
            }
        }
        return false;
    }
};