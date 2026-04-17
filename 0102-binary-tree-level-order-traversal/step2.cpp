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
    void scan(TreeNode* root, int level, vector<vector<int>>& nodes) {
        if (!root) {
            return;
        }
        if (nodes.size() < (level + 1)) {
            nodes.resize(level + 1);
        }
        nodes[level].push_back(root->val);
        if (root->left) {
            scan(root->left, level + 1, nodes);
        }
        if (root->right) {
            scan(root->right, level + 1, nodes);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> nodes;
        scan(root, level, nodes);
        return nodes;
    }
};
