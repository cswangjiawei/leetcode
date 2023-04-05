/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast) {
            fast = fast->next;
            if(fast){
                fast = fast->next;
            } 

            slow = slow->next;

            if (fast == slow) {
                break;
            }
        }

        if (fast == slow) {
            ListNode* ptr1 = slow;
            ListNode* ptr2 = head;

            while(ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }

        return nullptr;
    }
};