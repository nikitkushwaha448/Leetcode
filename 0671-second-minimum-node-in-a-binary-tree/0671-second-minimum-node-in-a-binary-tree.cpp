/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long firstMin;
    long secondMin = LONG_MAX;

    void dfs(TreeNode* root) {
        if (!root)
            return;

        if (root->val > firstMin) {
            secondMin = min(secondMin, (long)root->val);
        } else {
            dfs(root->right);
            dfs(root->left);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        firstMin = root->val;
        dfs(root);

        return secondMin == LONG_MAX ? -1 : secondMin;
    }
};