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
    int maxDepth(TreeNode* root) {
        if (root)
        {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }
        else
        {
            return 0;
        }
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        int result = 0;
        while (!Q.empty()) 
        {
            ++result;
            auto queue_size = Q.size();
            while(queue_size) 
            {
                auto cur_node = Q.front();
                Q.pop();
                --queue_size;
                if (cur_node->left != nullptr)
                {
                    Q.push(cur_node->left);
                }
                if (cur_node->right != nullptr)
                {
                    Q.push(cur_node->right);
                }
            }
        }

        return result;
    }
};