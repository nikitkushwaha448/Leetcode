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
     int height(TreeNode*root){
        if(root == NULL)
        return 0;
        int left = height(root->left);
        int right = height(root->right);

        return 1+ max(left,right);
     }
        void dfs(TreeNode*root, int row, int left, int right,vector<vector<string>>&ans){
            if(root == NULL)
            return;
            // find middle column
            int mid = (left + right)/2;
            // place current node
            ans[row][mid] = to_string(root->val);
            // Traverse left subtree
            dfs(root->left,row+1,left,mid -1,ans);
            // Traverse right subtree
            dfs(root->right, row+1,mid+1,right,ans);

        
     }
    vector<vector<string>> printTree(TreeNode* root) {
        if (root == NULL)
            return {};

        // Calculate height
        int h = height(root);

        // Calculate number of columns
        int w = (1 << h) - 1;

        // Create empty matrix
        vector<vector<string>> ans(
            h, vector<string>(w, "")
        );

        // Start DFS
        dfs(root, 0, 0, w - 1, ans);

        return ans;
    }
};