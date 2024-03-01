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
    string gameResult(ListNode* head) {
        int evenPoint = 0, oddPoint = 0;
        ListNode *curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val > curr->next->val) {
                evenPoint++;
            }else {
                oddPoint++;
            }
            curr = curr->next->next;
        }
        string ans;
        if (evenPoint > oddPoint) {
            ans = "Even";
        }else if (evenPoint < oddPoint) {
            ans = "Odd";
        }else {
            ans = "Tie";
        }
        return ans;
    }
};