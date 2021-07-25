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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* new_head = head;
        while (cur && cur->next)
        {
            if (cur == head) 
            {
                new_head = cur->next;
            }
            if (pre != nullptr)
            {
                pre->next = cur->next;
            }
            auto temp = cur->next;
            cur->next = temp->next;
            temp->next =cur;
            pre = cur;
            cur = cur->next;
        }
        return new_head;
    }
};


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* new_head=head;
        if (head && head->next)
        {
            new_head = head->next;
            auto temp = new_head->next;
            new_head->next = head;
            head->next = swapPairs(temp);
        }
        return new_head;
    }
};