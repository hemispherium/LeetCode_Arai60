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
    void dfs(TreeNode* root, int level, vector<vector<int>>& vvi) {
        if (!root) {
            return;
        }
        if (vvi.size() < (level + 1)) {
            vvi.resize(level + 1);
        }
        vvi[level].push_back(root->val);
        if (root->left) {
            dfs(root->left, level + 1, vvi);
        }
        if (root->right) {
            dfs(root->right, level + 1, vvi);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> vvi;
        dfs(root, level, vvi);
        return vvi;
    }
};
