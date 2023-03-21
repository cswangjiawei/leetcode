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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) {
            return {nullptr};
        }
        auto ans = generateTrees(1, n);
        return ans;
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            return {nullptr};
        }
        for (int i=start; i<=end; ++i) {
            auto left_trees = generateTrees(start, i-1);
            auto right_trees = generateTrees(i+1, end);
            for (auto& left_tree: left_trees) {
                for (auto& right_tree: right_trees) {
                    auto root = new TreeNode(i);
                    root->left = left_tree;
                    root->right = right_tree;
                    ans.push_back(root);
                }
            }

        }
        return ans;
    }
};