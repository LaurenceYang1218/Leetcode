/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, vector<long long>& levelSum) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int qsize = q.size();
            long long currSum = 0;
            for (int i = 0; i < qsize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currSum += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            levelSum.push_back(currSum);
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> levelSum;
        bfs(root, levelSum);
        sort(levelSum.begin(), levelSum.end(), [](long long a, long long b) {
            return a > b;
        });
        return k > levelSum.size() ? -1 : levelSum[k-1];
    }
};