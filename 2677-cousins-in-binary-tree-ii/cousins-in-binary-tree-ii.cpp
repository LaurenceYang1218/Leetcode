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
    void bfs(TreeNode* root, vector<int>& levelSum) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currLevelSum = 0;
            int qSize = q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* curr = q.front();
                q.pop();
                currLevelSum += curr->val;
                if (curr->left) 
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            levelSum.push_back(currLevelSum);
        }
        return;
    }

    void dfs(TreeNode* root, const vector<int>& levelSum, int currLevel) {
        int currSum = 0;
        if (currLevel == 0)
            root->val = 0;
        
        if (root->left) {
            currSum += root->left->val;
        }
        if (root->right) {
            currSum += root->right->val;
        }
        if (root->left)
            root->left->val = levelSum[currLevel + 1] - currSum;
        if (root->right)
            root->right->val = levelSum[currLevel + 1] - currSum;
        if (root->left) {
            dfs(root->left, levelSum, currLevel + 1);
        }
        if (root->right) {
            dfs(root->right, levelSum, currLevel + 1);
        }
        return;
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> levelSum;
        bfs(curr, levelSum);
        curr = root;
        int currLevel = 0;
        dfs(curr, levelSum, currLevel);
        return root;
    }
};