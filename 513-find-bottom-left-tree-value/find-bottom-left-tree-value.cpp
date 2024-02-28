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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> treeQ;
        TreeNode* curr = root;
        treeQ.push(curr);
        while(!treeQ.empty()) {
            int qLen = treeQ.size();
            curr = treeQ.front();
            treeQ.pop();
            if (curr->right != nullptr) {
                treeQ.push(curr->right);
            }
            if (curr->left != nullptr) {
                treeQ.push(curr->left);
            }
        }
        return curr->val;
    }
};