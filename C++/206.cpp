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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        while(head) {
            ListNode* tmp = head;
            head = head->next;
            tmp->next = pre;
            pre = tmp;
        }

        return pre;
    }
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* cur = head;
        while(cur) {
            ListNode* temp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = temp;
        }
        return dummy->next;

    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;

    }
};