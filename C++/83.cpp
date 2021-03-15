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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        while(pre && pre->next)
        {
            if (pre->val == pre->next->val)
            {
                pre->next = pre->next->next;
            }
            else
            {
                pre = pre->next;
            }
        }
        return head;
    }
};