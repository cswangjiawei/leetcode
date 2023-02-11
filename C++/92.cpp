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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pre = dummy;
        ListNode* nextt = dummy;
        --left;
        while(left) {
            pre = pre->next;
            nextt = nextt->next;
            --left;
            --right;
        }

        while(right) {
            nextt = nextt->next;
            --right;
        }

        ListNode* reverse_head = pre->next;
        pre->next = nullptr;
        ListNode* reverse_tail = nextt;
        ListNode* tail_next = nextt->next;
        nextt->next = nullptr;

        ListNode* new_head =  reverse_list(reverse_head);
        pre->next = new_head;
        reverse_head->next = tail_next;
        return dummy->next;

    }

    ListNode* reverse_list(ListNode* head) {
        ListNode* dummy = new ListNode();
        while (head) {
            ListNode* tmp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = tmp;
        }

        return dummy->next;
    }
};