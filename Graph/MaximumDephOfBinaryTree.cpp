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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        int maxDepth = 0;
        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            int depth = top.second;
            maxDepth = std::max(depth, maxDepth);
            if (top.first->right) {
                stack.push({top.first->right, depth + 1});
            }
            if (top.first->left) {
                stack.push({top.first->left, depth + 1});
            }
        }
        return maxDepth;
    }
};