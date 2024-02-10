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
    int ans = 0;
    void traverse(TreeNode *root, bool dir, int currLen) {
        if (root == nullptr) {
            return;
        }
        ans = max(ans, currLen);
        if (dir) {
            traverse(root->left, false, currLen + 1);
            traverse(root->right, true, 1);
        }else {
            traverse(root->left, false, 1);
            traverse(root->right, true, currLen + 1);
        }
        return;
    }   

    int longestZigZag(TreeNode* root) {
        traverse(root, false, 0);
        traverse(root, true, 0);    
        return ans;
    }
};