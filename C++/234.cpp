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
    bool isPalindrome(ListNode* head) {
        ListNode* mid_node = get_mid_node(head);

        ListNode* second_head = mid_node->next;
        mid_node->next = nullptr;
        ListNode* reverse_head = reverse(second_head);

        ListNode* cur1 = head;
        ListNode* cur2 = reverse_head;

        bool ans = true;
        while(cur2) {
            if (cur1->val != cur2->val) {
                ans = false;
                break;
            }
            cur2 = cur2->next;
            cur1 = cur1->next;
        }

        second_head = reverse(reverse_head);
        mid_node->next = second_head;

        return ans;
    }

    ListNode* get_mid_node(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = tmp;
        }

        return dummy->next;

    }
};