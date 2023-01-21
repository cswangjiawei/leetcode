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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==nullptr || head->next==nullptr) {
            return head;
        }

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* cur = dummy;
        while(cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                ListNode* tmp_cur = cur->next;
                while(tmp_cur) {
                    if (tmp_cur->val == x) {
                        cur->next = tmp_cur->next;
                        tmp_cur = tmp_cur->next;
                    } else {
                        break;
                    }
                }   
            } else {
                cur = cur->next;
            }            
        }
        

        return dummy->next;

    }
};