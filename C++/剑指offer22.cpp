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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* former = head;
        ListNode* latter = head;
        while(k)
        {
            former = former->next;
            --k;
        }
        while(former)
        {
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};