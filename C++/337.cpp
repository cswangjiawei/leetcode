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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> g;
        unordered_map<TreeNode*, int> f;
        int ans = 0;
        ans = dfs(root, g, f);
        return ans;

    }

    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& g, unordered_map<TreeNode*, int>& f) {
        if (root == nullptr) {
            return 0;
        }

        dfs(root->left, g, f);
        dfs(root->right, g, f);

        f[root] = g[root->left] + g[root->right] + root->val;
        g[root] = max(f[root->left], g[root->left]) + max(f[root->right], g[root->right]);

        return max(f[root], g[root]);
    }
};