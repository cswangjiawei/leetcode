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
    ListNode* rotateRight(ListNode* head, int k) {
        int list_size = 0;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            ++list_size;
            pre = cur;
            cur = cur->next;
        }

        if (list_size == 0) {
            return head;
        }

        k = k%list_size;
        if (k==0) {
            return head;
        }

        if (pre) {
            pre->next = head;
        }

        int n = list_size - k;
        cur = head;
        while (n) {
            pre = pre->next;
            cur = cur->next; 
            --n;
        }

        pre->next = nullptr;

        return cur;
    }
};