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
    TreeNode* prevNode;
    void inorder(TreeNode* root, int& minDiff) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, minDiff);
        if (prevNode != NULL) {
            minDiff = min(minDiff, abs(prevNode->val - root->val));
        }
        prevNode = root;
        inorder(root->right, minDiff);
    }

    int getMinimumDifference(TreeNode* root) {
        int ret = INT_MAX;
        inorder(root, ret);
        return ret;
    }
};