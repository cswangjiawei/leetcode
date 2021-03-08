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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> stk;
        long long pre_val = (long long)INT_MIN - 1;
        while (!stk.empty() || root)
        {
            while (root)
            {
                stk.push(root);
                root = root -> left;
            }
            auto inorder = stk.top();
            if (inorder -> val <= pre_val)
            {
                return false;
            }
            pre_val = inorder -> val;
            stk.pop();
            root = inorder -> right; 
        }

        return true;
        
    }
};