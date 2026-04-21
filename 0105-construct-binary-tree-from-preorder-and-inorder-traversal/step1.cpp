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
    void traverse(
        TreeNode* tree,
        const vector<int>& preorder,
        const vector<int>& inorder,
        int pre_left,
        int pre_right,
        int in_left,
        int in_right
    ) {
        auto it = find(inorder.begin() + in_left, inorder.begin() + in_right, preorder[pre_left]);
        if (it - inorder.begin() != in_left) {
            tree->left = new TreeNode(preorder[pre_left + 1]);
            traverse(
                tree->left,
                preorder,
                inorder,
                pre_left + 1,
                pre_left + it - (inorder.begin() + in_left),
                in_left,
                it - inorder.begin() - 1
            );
        }
        if (it - inorder.begin() != in_right) {
            tree->right = new TreeNode(preorder[pre_left + it - (inorder.begin() + in_left) + 1]);
            traverse(
                tree->right,
                preorder,
                inorder,
                pre_left + it - (inorder.begin() + in_left) + 1,
                pre_right,
                it - inorder.begin() + 1,
                in_right
            );
        } 
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* tree = new TreeNode(preorder[0]);
        int size = preorder.size();
        traverse(tree, preorder, inorder, 0, size - 1, 0, size - 1);
        return tree;
    }
};
