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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        getPathSum(root);
        return maxSum;    
    }
    int getPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftPathSum = max(getPathSum(root->left), 0);
        int rightPathSum = max(getPathSum(root->right), 0);
        maxSum = max(maxSum, leftPathSum + rightPathSum + root->val);
        return root->val + max(leftPathSum, rightPathSum);
    }
};