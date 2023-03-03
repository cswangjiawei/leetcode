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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (auto &list_e: lists) {
            ans = mergeTwoLists(ans, list_e);
        }

        return ans;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* prev = dummy;
        ListNode* cur = nullptr;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur = list1;
                list1 = list1->next;
            } else {
                cur = list2;
                list2 = list2->next;
            }
            prev->next = cur;
            prev = cur;

        }


        if (list2) {
            list1 = list2;
        }

        prev->next = list1;

        return dummy->next;
    }
};