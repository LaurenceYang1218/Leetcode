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
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy, *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            ListNode *first = curr, *second = curr->next;
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            curr = first->next;
        }
        return dummy->next;
    }
};