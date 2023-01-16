/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==nullptr) {
            return nullptr;
        }
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((root->val==p->val || root->val==q->val) && (lson || rson))) {
            ans = root;
        }
        else {
            lowestCommonAncestor(root->left, p, q);
            lowestCommonAncestor(root->right, p, q);
        }

        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return false;
        }
        if(root->val == p->val || root->val == q->val) {
            return true;
        }
        bool lflag = dfs(root->left, p, q);
        bool rflag = dfs(root->right, p, q);

        return lflag || rflag;
    }
};