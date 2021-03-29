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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* pre_head = new ListNode();

        pre_head->next = head;
        ListNode* pre = pre_head;
        ListNode* cur = head;
        while (cur)
        {
            if (cur->val == val)
            {
                pre->next = cur->next;
            }
            else
            {
                pre = pre->next;
            }
            cur = cur->next;
        }
        return pre_head->next;
    }
};