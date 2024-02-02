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
    void traverse(TreeNode* root, vector<int>& leafs) {
        if (root->left == nullptr && root->right == nullptr) {
            leafs.push_back(root->val);
            return;
        } 
        if (root->left != nullptr) {
            traverse(root->left, leafs);
        }
        if (root->right != nullptr) {
            traverse(root->right, leafs);
        }
    }   

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;   
        traverse(root1, leaf1);
        traverse(root2, leaf2);    
        return (leaf1 == leaf2);
    }
};