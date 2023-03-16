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
    int ans = INT_MAX;
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        myMinDepth(root, 0);
        return ans;
    }

    void myMinDepth(TreeNode* root, int tmp) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            ++tmp;
            ans = min(ans, tmp);
        }
         else {
            ++tmp;
            myMinDepth(root->left, tmp);
            myMinDepth(root->right, tmp);
        }
        
    }
};