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

    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        // Queue stores node and its index
        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {

            int n = q.size();

            // First index of current level
            unsigned long long first = q.front().second;

            unsigned long long last = 0;

            for (int i = 0; i < n; i++) {

                auto p = q.front();
                q.pop();

                TreeNode* node = p.first;

                // Normalize index to avoid overflow
                unsigned long long idx = p.second - first;

                last = idx;

                // Left child
                if (node->left) {
                    q.push({
                        node->left,
                        2 * idx
                    });
                }

                // Right child
                if (node->right) {
                    q.push({
                        node->right,
                        2 * idx + 1
                    });
                }
            }

            // Calculate width of current level
            ans = max(ans, last + 1);
        }

        return (int)ans;
    }
};