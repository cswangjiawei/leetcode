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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* head_1 = head;
        ListNode* head_2 = nullptr;
        ListNode* prev_head_2 = nullptr;
        int i = 1;
        while (head_1 != nullptr)
        {
            if (i == n)
            {
                head_2 = head;
            }
            else
            {
                if (head_2 != nullptr)
                {
                    prev_head_2 = head_2;
                    head_2 = head_2->next;
                }
            }
            if (head_1->next == nullptr)
            {
                if (prev_head_2 != nullptr)
                {
                    prev_head_2->next = head_2->next;
                    head_2->next = nullptr;
                }
                else
                {
                    head = head->next;
                    
                }
                break;
            }
            head_1 = head_1->next;
            ++i;
        }
        return head;
    }
};