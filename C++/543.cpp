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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int ans = 0;
        myDiameterOfBinaryTree(root, ans);
        return ans;
    }

    void myDiameterOfBinaryTree(TreeNode* root, int& ans) {
        int left_tree_height = tree_height(root->left, ans);
        int right_tree_height = tree_height(root->right, ans);
        ans = max(ans, left_tree_height + right_tree_height);
    }

    

    int tree_height(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return 0;
        }

        int left_tree_height = tree_height(root->left, ans);
        int right_tree_height = tree_height(root->right, ans);
        ans = max(ans, left_tree_height+right_tree_height);

        return max(left_tree_height, right_tree_height) + 1;
    }
};

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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr || root->left == nullptr && root->right == nullptr)
        {
            return 0;
        }
        int left_ans = diameterOfBinaryTree(root->left);
        int right_ans = diameterOfBinaryTree(root->right);
        int self_ans = tree_height(root->left) + tree_height(root->right);
        return max(max(left_ans, right_ans), self_ans);
    }

    int tree_height(TreeNode*  root)
    {
        if (root)
        {
            return 1 + max(tree_height(root->left), tree_height(root->right));
        } 
        return 0;
    }
};