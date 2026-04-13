class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int leftDepth = maxDepth(root->leftNode);
        int rightDepth = maxDepth(root->rightNode);

        return max(leftDepth, rightDepth) + 1;
    }
};
