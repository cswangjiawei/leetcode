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
private:
 vector<int> ans;
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) {
            return ans;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        ans.emplace_back(root->val);
        return ans;
    }
};