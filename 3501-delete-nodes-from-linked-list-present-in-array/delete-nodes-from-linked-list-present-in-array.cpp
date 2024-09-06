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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> hashNums(nums.begin(), nums.end());
        ListNode* dummyHead = new ListNode();
        dummyHead->next = head;
        ListNode* curr = dummyHead;
        
        while (curr->next) {
            if (hashNums.contains(curr->next->val)) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummyHead->next;
    }
};