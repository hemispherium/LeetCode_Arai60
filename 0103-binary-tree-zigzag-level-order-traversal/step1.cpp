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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> nodes;
        nodes.push(root);

        bool toggle = false;
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();

                level.push_back(node->val);

                if (node->left) nodes.push(node->left);
                if (node->right) nodes.push(node->right);
            }

            if (toggle) {
                reverse(level.begin(), level.end());
            }

            toggle = !toggle;

            result.push_back(level);
        }

        return result;
    }
};
