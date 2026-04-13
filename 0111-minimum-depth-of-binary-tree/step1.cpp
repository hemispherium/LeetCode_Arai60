class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        if (leftDepth == 0) {
            return rightDepth + 1;
        }

        if (rightDepth == 0) {
            return leftDepth + 1;
        }

        return min(leftDepth, rightDepth) + 1;
    }
};
