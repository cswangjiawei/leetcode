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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        if (!root) {
            return ans;
        }
        q.push(root);
        while (!q.empty()) {
            int q_size = static_cast<int>(q.size());
            vector<int> tmp;
            while (q_size) {
                auto cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                --q_size;
            }
            ans.push_back(tmp);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};