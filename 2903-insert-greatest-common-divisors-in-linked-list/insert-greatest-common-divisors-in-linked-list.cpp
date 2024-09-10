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
    int gcd(int a, int b) {
        if (a % b == 0) {
            return b;
        }else {
            return gcd(b, a % b);
        }
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* currNode = head;
        ListNode* nextNode = currNode->next;
        if (nextNode == NULL)
            return head;

        while (currNode && nextNode) {
            ListNode* gcdNode = new ListNode(gcd(currNode->val, nextNode->val));
            currNode->next = gcdNode;
            gcdNode->next = nextNode;
            currNode = nextNode;
            nextNode = nextNode->next;
        } 
        return head;
    }
};