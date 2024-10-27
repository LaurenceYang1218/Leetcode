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
    int maxHeight[100005] = {0};
    int currMaxHeight = 0;
    void preorder(TreeNode* root, int currHeight) {
        if (root == nullptr) {
            return;
        }
        maxHeight[root->val] = currMaxHeight;
        currMaxHeight = max(currMaxHeight, currHeight);
        preorder(root->left, currHeight + 1);
        preorder(root->right, currHeight + 1);
    }

    void preorderRev(TreeNode* root, int currHeight) {
        if (root == nullptr) {
            return;
        }
        maxHeight[root->val] = max(maxHeight[root->val], currMaxHeight);
        currMaxHeight = max(currMaxHeight, currHeight);
        preorderRev(root->right, currHeight + 1);
        preorderRev(root->left, currHeight + 1);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> ret;
        preorder(root, 0);
        currMaxHeight = 0;
        preorderRev(root, 0);
        for (int i = 0; i < queries.size(); i++) {
            ret.push_back(maxHeight[queries[i]]);
        }
        return ret;
    }
};