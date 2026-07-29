class Solution {
public:
    vector<string> ans;

    void dfs(TreeNode* root, vector<int>& path) {
        if (!root) return;

        path.push_back(root->val);

        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size(); i++) {
                s += to_string(path[i]);
                if (i != path.size() - 1)
                    s += "->";
            }
            ans.push_back(s);
        }

        dfs(root->left, path);
        dfs(root->right, path);

        path.pop_back(); 
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        dfs(root, path);
        return ans;
    }
};