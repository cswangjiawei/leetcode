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


class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        int length = 0;
        ListNode* cur = head;
        while (cur) {
            ++length;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode();
        dummy->next = head;

        for (int sub_length = 1; sub_length<length; sub_length<<=1) {
            ListNode* prev_tail = dummy;
            ListNode* head1 = dummy->next;
            while (head1) {
                cur = head1;
                ListNode* prev = nullptr;
                for (int i=0; i<sub_length && cur; ++i) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = nullptr;
                ListNode* head2 = cur;
                for (int i=0; i<sub_length && cur; ++i) {
                    prev = cur;
                    cur = cur->next;
                }
                if (cur) {
                    prev->next = nullptr;
                }
                ListNode* merge_head = merge(head1, head2);
                prev_tail->next = merge_head;
                while (merge_head->next) {
                    merge_head = merge_head->next;
                }
                prev_tail = merge_head;
                head1 = cur;
            }
        }
        return dummy->next; 
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                cur = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                cur = head2;
                head2 = head2->next;
            }
        }
        if (head2) {
            head1 = head2;
        }
        cur->next = head1;
        return dummy->next;
    }
};