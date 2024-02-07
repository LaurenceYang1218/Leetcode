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
    int pairSum(ListNode* head) {
        vector<int> vec;
        ListNode *curr = head;
        while (curr != nullptr) {
            vec.push_back(curr->val);
            curr = curr->next;
        }
        int l = 0, r = vec.size()-1;
        int ans = 0;
        while (l < r) {
            int pairSum = vec[l] + vec[r];
            ans = max(ans, pairSum);
            l++;
            r--;
        }
        return ans;
    }
};