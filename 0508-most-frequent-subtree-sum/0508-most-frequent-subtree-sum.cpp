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
    unordered_map<int, int> freq;
    int maxFreq = 0;

    int dfs(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);

        int sum = root->val + leftSum + rightSum;

        freq[sum]++;
        maxFreq = max(maxFreq, freq[sum]);

        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);

        vector<int> ans;

        for (auto& p : freq) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
