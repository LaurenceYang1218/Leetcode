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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode* curr = head;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirCnt = 0;
        int idx = 0, jdx = 0, dirX, dirY;
        while (curr) {
            dirX = dirs[dirCnt][0];
            dirY = dirs[dirCnt][1];
            res[idx][jdx] = curr->val;
            if (idx + dirX < 0 || idx + dirX >= m || jdx + dirY < 0 || jdx + dirY >= n || res[idx+dirX][jdx+dirY] != -1) {
                dirCnt = (dirCnt + 1) % 4;
            }
            idx += dirs[dirCnt][0]; jdx += dirs[dirCnt][1];
            curr = curr->next;
        }
        return res;
    }
};