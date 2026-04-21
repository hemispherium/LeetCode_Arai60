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
    unordered_map<int, int> inorder_val_to_index;

    TreeNode* build(
        const vector<int>& preorder,
        int preL,
        int preR,
        int inL
    ) {
        if (preL > preR) {
            return nullptr;
        }

        int rootVal = preorder[preL];
        int rootIdx = inorder_val_to_index[rootVal];
        int leftSize = rootIdx - inL;

        TreeNode* root = new TreeNode(rootVal);

        root->left = build(preorder, preL + 1, preL + leftSize, inL);
        root->right = build(preorder, preL + leftSize + 1, preR, rootIdx + 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder_val_to_index[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, 0);
    }
};
