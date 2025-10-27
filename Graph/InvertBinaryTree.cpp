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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        std::stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            auto top = stack.top();
            stack.pop();
            if (!top) continue;

            stack.push(top->left);
            stack.push(top->right);
            auto temp = top->left;
            top->left = top->right;
            top->right = temp;
        }
        return root;
    }
};