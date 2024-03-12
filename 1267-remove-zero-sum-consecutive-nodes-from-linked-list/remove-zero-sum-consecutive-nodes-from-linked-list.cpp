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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> listMap;
        ListNode* front = new ListNode(0, head);
        ListNode* curr = front;
        int prefixSum = 0;
        while (curr != nullptr) {
            prefixSum += curr->val;
            if (listMap.find(prefixSum) != listMap.end()) {
                ListNode *prev = listMap[prefixSum];
                ListNode *l = prev->next;
                int p = prefixSum + l->val;
                while (p != prefixSum) {
                    listMap.erase(p);
                    l = l->next;
                    p += l->val;
                }
                prev->next = curr->next;
            }else { 
                listMap[prefixSum] = curr;
            }
            curr = curr->next;
        }
        return front->next;
    }
};