struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    bool isSame(TreeNode* node1, TreeNode* node2)
    {
        if(!node1 && !node2) return true;
        else
        {
            if (node1 && node2)
            {
                if (node1->val != node2->val) return false;
                return isSame(node1->left, node2->right) && isSame(node1->right, node2->left);
            } 
            else return false;
        }
    }
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSame(root->left, root->right);
    }
};