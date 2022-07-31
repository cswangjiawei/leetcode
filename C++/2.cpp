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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            auto num1 = l1 ? l1->val:0;
            auto num2 = l2 ? l2->val:0;
            
            auto num_sum = num1 + num2 + carry;
            carry = num_sum / 10;

            if (!head) {
                head = new ListNode(num_sum % 10);
                tail = head;
            }
            else {
                tail->next = new ListNode(num_sum % 10);
                tail = tail->next;
            }
            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;
        }
        if (carry) {
            tail->next = new ListNode(carry);
        }
        return head;
    }
};