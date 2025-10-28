#include <vector>
#include <stack>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        std::vector<std::vector<int>> result;
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, 1});
        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            int depth = top.second;
            if (result.size() < depth) {
                result.push_back({top.first->val});
            } else {
                result[depth - 1].push_back({top.first->val});
            }
            if (top.first->right) {
                stack.push({top.first->right, depth + 1});
            }
            if (top.first->left) {
                stack.push({top.first->left, depth + 1});
            }
        }
        return result;
    }
};