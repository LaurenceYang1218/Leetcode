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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        } 
        queue<TreeNode *> treeQ;
        treeQ.push(root);
        while (!treeQ.empty()) {
            vector<int> vec;
            int qLen = treeQ.size();
            for (int i = 0; i < qLen; i++) {
                TreeNode *curr = treeQ.front();
                treeQ.pop();
                if (curr->left != nullptr) {
                    treeQ.push(curr->left);
                }
                if (curr->right != nullptr) {
                    treeQ.push(curr->right);
                }
                vec.push_back(curr->val);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};