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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* last_sorted = head;
        ListNode* cur = head->next;

        while(cur) {
            if(cur->val >= last_sorted->val) {
                last_sorted = cur;
            } else {
                ListNode* prev = dummy;
                while(prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                last_sorted->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }

            cur = last_sorted->next;
        }

        return dummy->next;
        
    }
};