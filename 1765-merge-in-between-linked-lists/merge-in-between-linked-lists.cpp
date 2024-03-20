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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *start = nullptr, *end = nullptr;
        ListNode *currList1 = list1;
        for (int i = 0; i < b; i++) {
            if (i == a-1) {
                start = currList1;
            }
            currList1 = currList1->next;
        }
        end = currList1->next;
        start->next = list2;
        ListNode *currList2 = list2;
        while (currList2->next != nullptr) {
            currList2 = currList2->next;
        }
        currList2->next = end;
        return list1;
    }
};