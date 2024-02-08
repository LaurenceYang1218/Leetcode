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
    int maxLevelSum(TreeNode* root) {
        int ans = 0, allSum = INT_MIN, currLevel = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int queueLength = q.size();
            int maxSum = 0;
            for (int i = 0; i < queueLength; i++) {
                TreeNode *node = q.front();
                q.pop();
                maxSum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (maxSum > allSum) {
                allSum = maxSum;
                ans = currLevel;
            }
            currLevel++;
        }
        return ans;
    }
};