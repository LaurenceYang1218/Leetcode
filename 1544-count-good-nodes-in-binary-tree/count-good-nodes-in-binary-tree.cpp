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
    int cnt = 0;
    void traverse(TreeNode* root, int maxVal) {
        if (root->val >= maxVal) {
            maxVal = root->val;
            cnt++;
        }
        if (root->left != nullptr) {
            traverse(root->left, maxVal);
        }
        if (root->right != nullptr) {
            traverse(root->right, maxVal);
        }
    }

    int goodNodes(TreeNode* root) {
        traverse(root, INT_MIN);
        return cnt;
    }
};