/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* cur = head;
        int list_size = 0;
        while (cur) {
            ++list_size;
            cur = cur->next;
        }

        return mySortedListToBST(head, list_size);
    }

    TreeNode* mySortedListToBST(ListNode* head, int list_size) {
        if (list_size <= 0 || head==nullptr) {
            return nullptr;
        }
        if (list_size == 1) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* cur = head;
        int n = list_size / 2;
    
        int tmp = n;
        while (tmp) {
            cur = cur->next;
            --tmp;
        }
        
        TreeNode* root = new TreeNode(cur->val);
        root->left = mySortedListToBST(head, n);
        root->right = mySortedListToBST(cur->next, list_size-n-1);

        return root;
    }
};