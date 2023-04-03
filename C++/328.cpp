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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* odd = nullptr;
        ListNode* even = nullptr;
        ListNode* even_head = nullptr;

        ListNode* cur = head;
        int count = 1;
        while (cur) {
            if (count%2 == 1) {
                if (!odd) {
                    odd = cur;
                } else {
                    odd->next = cur;
                    odd = cur;
                }
            } else {
                if (!even) {
                    even = cur;
                    even_head = cur;
                } else {
                    even->next = cur;
                    even = cur;
                }
            }
            cur = cur->next;
            ++count;
        }

        even->next = nullptr;
        odd->next = even_head;
        return head;

    }
};