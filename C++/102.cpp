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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        queue<TreeNode*> Q;
        if (root) {
            Q.push(root);
        }
        while(!Q.empty()) {
            vector<int> vec;
            int q_size = Q.size();
            while(q_size) {
                auto tmp = Q.front();
                vec.emplace_back(tmp->val);
                if (tmp->left) {
                    Q.push(tmp->left);
                }
                if (tmp->right) {
                    Q.push(tmp->right);
                }
                Q.pop();
                --q_size;
            }
            result.emplace_back(vec);
        }
        return result;
    }
};