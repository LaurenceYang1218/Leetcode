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
    long long cnt = 0, target;
    unordered_map<long long, int> numMap;
    void traverse(TreeNode* root, long long currSum) {
        if (root == nullptr) {
            return;
        }
        currSum += root->val;
        if (currSum == target) {
            cnt++;
        }
        if (numMap.find(currSum - target) != numMap.end()) {
            cnt += numMap[currSum - target];
        }
        numMap[currSum]++;
        traverse(root->left, currSum);
        traverse(root->right, currSum);
        if (numMap[currSum] == 0) {
            numMap.erase(currSum);
        } else { 
            numMap[currSum]--;
        }
        return;
    }   

    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        traverse(root, 0);    
        return cnt;    
    }
};