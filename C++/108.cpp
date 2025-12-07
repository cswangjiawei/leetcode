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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        return mySortedArrayToBST(nums, 0, n-1);

    }

    TreeNode* mySortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = mySortedArrayToBST(nums, left, mid-1);
        root->right = mySortedArrayToBST(nums, mid+1, right);
        return root;
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        TreeNode* ans;
        int n = nums.size();
        int mid = n/2;
        ans = new TreeNode(nums[mid]);
        vector<int> left_nums = vector(nums.begin(), nums.begin() + mid);
        ans->left = sortedArrayToBST(left_nums);
        vector<int> right_nums = vector(nums.begin()+mid+1, nums.end());
        ans->right = sortedArrayToBST(right_nums);

        return ans;

    }
};