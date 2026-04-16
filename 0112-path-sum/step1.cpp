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
    int flag = false;

    void scan(TreeNode* root, int sum, int targetSum) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            flag = flag || (sum == targetSum);
            return;
        }
        if (root->left != nullptr) {
            scan(root->left, sum + root->left->val, targetSum);
        }
        if (root->right != nullptr) {
            scan(root->right, sum + root->right->val, targetSum);
        }
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        scan(root, root->val, targetSum);
        return flag;
    }
};
