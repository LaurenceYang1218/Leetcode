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
    int diameter = 0;
    int countDiameter(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftPath = countDiameter(root->left);
        int rightPath = countDiameter(root->right);
        diameter = max(diameter, leftPath + rightPath);
        return max(leftPath, rightPath) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        countDiameter(root);
        return diameter;
    }
};