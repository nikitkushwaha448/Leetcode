/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int xDepth = -1, yDepth = -1;
    TreeNode* xParent = nullptr;
    TreeNode* yParent = nullptr;

    void dfs(TreeNode* root, TreeNode* parent, int depth, int x, int y) {
        if (root == nullptr)
            return;

        if (root->val == x) {
            xDepth = depth;
            xParent = parent;
        }

        if (root->val == y) {
            yDepth = depth;
            yParent = parent;
        }

        dfs(root->left, root, depth + 1, x, y);
        dfs(root->right, root, depth + 1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, nullptr, 0, x, y);

        return (xDepth == yDepth) && (xParent != yParent);
    }
};