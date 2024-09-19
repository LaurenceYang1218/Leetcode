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
    map<pair<int, int>, vector<TreeNode*>> memo;
    vector<TreeNode*> generatePossibleTrees(int start, int end) {
        if (memo.find({start, end}) != memo.end()) {
            return memo[{start, end}];
        }
        vector<TreeNode*> ret;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generatePossibleTrees(start, i-1);
            vector<TreeNode*> rightTrees = generatePossibleTrees(i+1, end);
            for (TreeNode* leftTree : leftTrees) {
                for (TreeNode* rightTree : rightTrees) {
                    TreeNode* root = new TreeNode(i, leftTree, rightTree);
                    ret.push_back(root);
                }
            }
        }
        if (ret.empty()) {
            TreeNode* root = nullptr;
            ret.push_back(root);
        }
        memo[{start, end}] = ret;
        return ret;
    } 

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret = generatePossibleTrees(1, n);
        return ret;
    }
};