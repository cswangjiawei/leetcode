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
    int summ = INT_MIN;

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return summ;

    }

    int maxGain(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_max_gain = maxGain(root->left);
        int right_max_gain = maxGain(root->right);

        summ = max(summ, left_max_gain + right_max_gain + root->val);

        return max(max(left_max_gain, right_max_gain) + root->val, 0);
    }
};