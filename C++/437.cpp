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
    int pathSum(TreeNode* root, long long targetSum) {
        int ans = 0;
        if (root == nullptr) {
            return 0;
        }

        ans += root_sum(root, targetSum);
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);

        return ans;

    }

    int root_sum(TreeNode* root, long long targetSum) {
        int ret = 0;
        if (root == nullptr) {
            return 0;
        }

        if (root->val == targetSum) {
            ++ret;
        }

        ret += root_sum(root->left, targetSum - root->val);
        ret += root_sum(root->right, targetSum - root->val);
        return ret;

    }
};