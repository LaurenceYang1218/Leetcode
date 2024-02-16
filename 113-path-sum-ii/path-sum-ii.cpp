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
    vector<vector<int>> ans;
    void traverse(TreeNode *root, int remainSum, vector<int> vec) {
        if (root == nullptr) {
            return;
        }
        vec.push_back(root->val);
        remainSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (remainSum == 0) {
                ans.push_back(vec);
            }
        }else {
            traverse(root->left, remainSum, vec);
            traverse(root->right, remainSum, vec);
        }
        return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        traverse(root, targetSum, vec);
        return ans;
    }
};