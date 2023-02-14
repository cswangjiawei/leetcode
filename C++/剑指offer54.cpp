/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        vector<int> vec;
        inorder(root, vec, k);
        return vec[k-1];
    }

    void inorder(TreeNode* root, vector<int>& vec, int k) {
        if (vec.size() == k) {
            return;
        }
        if  (root->right) {
            inorder(root->right, vec, k);
        }
        vec.emplace_back(root->val);
        if (root->left) {
            inorder(root->left, vec, k);
        }

    }
};