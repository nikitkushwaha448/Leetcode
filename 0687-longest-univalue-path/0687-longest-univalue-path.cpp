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
    int ans = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        int leftPath = 0;
        int rightPath = 0;

        if (root->left && root->left->val == root->val)
            leftPath = left + 1;

        if (root->right && root->right->val == root->val)
            rightPath = right + 1;

        ans = max(ans, leftPath + rightPath);

        return max(leftPath, rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};