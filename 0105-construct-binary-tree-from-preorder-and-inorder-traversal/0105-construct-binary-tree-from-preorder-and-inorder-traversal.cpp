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

    int search(vector<int>& inorder, int start,
               int end, int value) {

        for (int i = start; i <= end; i++) {
            if (inorder[i] == value)
                return i;
        }

        return -1;
    }

    TreeNode* solve(vector<int>& preorder,
                    vector<int>& inorder,
                    int inStart, int inEnd,
                    int& preIndex) {

        if (inStart > inEnd)
            return nullptr;

        //  Find root from preorder
        int rootVal = preorder[preIndex++];

        TreeNode* root = new TreeNode(rootVal);

        //  Find root position in inorder
        int inIndex = search(inorder, inStart,
                             inEnd, rootVal);

        //  Construct left subtree
        root->left = solve(preorder, inorder,
                           inStart, inIndex - 1,
                           preIndex);

        //  Construct right subtree
        root->right = solve(preorder, inorder,
                            inIndex + 1, inEnd,
                            preIndex);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int preIndex = 0;

        return solve(preorder, inorder,
                     0, inorder.size() - 1,
                     preIndex);
    }
};
