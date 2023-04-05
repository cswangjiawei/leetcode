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
    void reorderList(ListNode* head) {
        ListNode* mid_node = get_secondhead(head);
        ListNode* second_head = mid_node->next;
        mid_node->next = nullptr;
        ListNode* reverse_head = reverse(second_head);
        merge_list(head, reverse_head);
        
    }

    ListNode* get_secondhead(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (slow && fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next;
            fast = fast->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur) {
            auto tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = tmp;
        }

        return dummy->next;
    }

    void merge_list(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head1 && head2) {
            cur->next = head1;
            auto head1_next = head1->next;
            head1->next = head2;
            cur = head2;
            head1 = head1_next;
            head2 = head2->next;
        }
        cur->next = head1;

    }
};