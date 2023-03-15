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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = static_cast<int>(inorder.size());
        for (int i=0; i<n; ++i) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = myBuildTree(inorder, postorder, mp, 0, n-1, 0, n-1);
        return root;

    }

    TreeNode* myBuildTree(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp,
    int in_start, int in_end, int post_start, int post_end) {
        if (in_start > in_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[post_end]);
        int root_pos_inorder = mp[postorder[post_end]];
        int left_tree_len = root_pos_inorder - in_start;
        root->left = myBuildTree(inorder, postorder, mp, in_start, root_pos_inorder-1, post_start, post_start+left_tree_len-1);
        root->right = myBuildTree(inorder, postorder, mp, root_pos_inorder+1, in_end, post_start+left_tree_len, post_end-1);
        return root;
    }
};