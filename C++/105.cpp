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
    unordered_map<int, int> map1;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i=0; i<n; ++i)
        {
            map1.emplace(make_pair(inorder[i], i));
        }
        return build_tree(preorder, 0, n-1, inorder, 0, n-1);
    }

    TreeNode* build_tree(vector<int>& preorder, int pre_s, int pre_e, vector<int>& inorder, int in_s, int in_e)
    {
        if (pre_s > pre_e) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_s]);
        int inorder_root = map1[preorder[pre_s]];
        int left_tree_len = inorder_root - in_s;
        int right_tree_len = in_e - inorder_root;
        root->left = build_tree(preorder, pre_s+1, pre_s+left_tree_len, inorder, in_s, inorder_root-1);
        root->right = build_tree(preorder, pre_s+left_tree_len+1, pre_e, inorder, inorder_root+1, in_e);
        return root;
    }
};