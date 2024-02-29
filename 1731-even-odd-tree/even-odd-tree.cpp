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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue<TreeNode *> treeQ;
        treeQ.push(root);
        while (!treeQ.empty()) {
            int qLen = treeQ.size();
            int tempVal = (level % 2 == 0) ? 0 : INT_MAX;
            for (int i = 0; i < qLen; i++) {
                TreeNode *curr = treeQ.front();
                treeQ.pop();
                if (level % 2 == 0) {
                    if (curr->val % 2 == 0 || curr->val <= tempVal) {
                        return false;
                    }
                }else {
                    if (curr->val % 2 != 0 || curr->val >= tempVal) {
                        return false;
                    }
                }
                if (curr->left != nullptr) {
                    treeQ.push(curr->left);
                }
                if (curr->right != nullptr) {
                    treeQ.push(curr->right);
                }
                tempVal = curr->val;
            }
            level++;
        }
        return true;
    }
};