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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        in_order(root, result);
        return result;
    }

    void in_order(TreeNode* root, vector<int>& result)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root -> left != nullptr)
        {
            in_order(root -> left, result);
        }
        result.emplace_back(root -> val); 
        if (root -> right != nullptr)
        {
            in_order(root -> right, result);
        }
    }
};