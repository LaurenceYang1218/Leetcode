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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;
            int val = val1 + val2 + carry;
            carry = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        return head->next;
    }
};