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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        curr = head;
        int nodePerIdx = n / k, mod = n % k;
        vector<ListNode*> ret;
        for (int i = 0; i < k; i++) {
            ListNode* newListDummyHead = new ListNode();
            ListNode* newListCurr = newListDummyHead;
            for (int j = 0; j < nodePerIdx; j++) {
                ListNode* newNode = new ListNode(curr->val);
                newListCurr->next = newNode;
                newListCurr = newListCurr->next;
                curr = curr->next;
            }
            if (i < mod) {
                ListNode* newNode = new ListNode(curr->val);
                newListCurr->next = newNode;
                newListCurr = newListCurr->next;
                curr = curr->next;
            }
            ret.push_back(newListDummyHead->next);
        }
        return ret;
    }
};