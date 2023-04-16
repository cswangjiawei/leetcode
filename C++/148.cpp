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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* midnode = get_midnode(head);
        ListNode* head2 = midnode->next;
        midnode->next = nullptr;

        return merge(sortList(head), sortList(head2));
    }

    

    ListNode* get_midnode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;

        ListNode* dummy = new ListNode();
        ListNode* pre = dummy;
        while (cur1 && cur2) {
            if (cur1->val < cur2->val) {
                pre->next = cur1;
                pre =cur1;
                cur1 = cur1->next;
            } else {
                pre->next = cur2;
                pre = cur2;
                cur2 = cur2->next;
            }
        }

        if (cur2) {
            cur1 = cur2;
        }
        pre->next = cur1;

        return dummy->next;
    }
};