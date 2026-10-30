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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode*newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root,val,depth,1);

        return root;
    }
    void dfs(TreeNode*node,int val,int depth,int level){
        if(node == nullptr)
        return;

        if(level == depth -1){
        //   store original children
        TreeNode*oldleft = node->left;
        TreeNode*oldRight = node->right;

        // create new children
        node->left = new TreeNode(val);
        node->right = new TreeNode(val);

        node->left->left = oldleft;
        node->right->right = oldRight;

        return;
        }
        dfs(node->left, val,depth,level +1);
        dfs(node->right, val,depth, level +1);
    }
};