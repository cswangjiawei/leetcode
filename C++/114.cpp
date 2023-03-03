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
    void flatten(TreeNode* root) {
        vector<TreeNode*> vec;
        preorder(root, vec);

        int n = static_cast<int>(vec.size());
        for (int i=0; i<n-1; ++i) {
            vec[i]->right = vec[i+1];
            vec[i]->left = nullptr;
        }
        
    }

    void preorder(TreeNode* root, vector<TreeNode*>& vec) {
        if (root == nullptr) {
            return;
        }
        vec.emplace_back(root);
        preorder(root->left, vec);
        preorder(root->right, vec);
    }
};