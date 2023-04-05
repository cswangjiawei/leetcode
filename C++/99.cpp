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
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        auto swap_two = find_swap(vec);
        my_recover(root, swap_two);

    }

    void inorder(TreeNode* root, vector<int>& vec) {
        if (!root) {
            return;
        }
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }

    pair<int, int> find_swap(vector<int>& vec) {
        int index1 = -1;
        int index2 = -1;

        int n = static_cast<int>(vec.size());
        for (int i=0; i<n-1; ++i) {
            if (vec[i] > vec[i+1]) {
                index2 = i+1;
                if (index1 == -1) {
                    index1 = i;
                }
            }
            
        }

        return {vec[index1], vec[index2]};
    }

    void my_recover(TreeNode* root, pair<int, int>& swap_two) {
        if (!root) {
            return;
        }
        if (root->val == swap_two.first || root->val == swap_two.second) {
            root->val = root->val == swap_two.first ? swap_two.second : swap_two.first;
        }
        my_recover(root->left, swap_two);
        my_recover(root->right, swap_two);
        
    }
};