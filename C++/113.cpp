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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > result;
        vector<int> path_vec;
        dfs(root, targetSum, result, path_vec);
        return result;
    }

    void dfs(TreeNode* root, int targetSum, vector<vector<int> > &result, vector<int> &path_vec)
    {
        if (!root)
        {
            return;
        }
        targetSum -= root->val;
        path_vec.emplace_back(root -> val);
        if (targetSum == 0 && root->left==nullptr && root->right==nullptr)
        {
            result.emplace_back(path_vec);
        }
        dfs(root -> left, targetSum, result, path_vec);
        dfs(root -> right, targetSum, result, path_vec);
        path_vec.pop_back();
    }
};