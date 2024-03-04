class Solution {
public:
    vector<string> ans;
    void backtrack(string currStr, int n, int leftCnt, int rightCnt) {
        if (currStr.length() == 2 * n) {
            ans.push_back(currStr);
            return;
        }   
        if (leftCnt < n) {
            backtrack(currStr + '(', n, leftCnt+1, rightCnt);
        }
        if (leftCnt > rightCnt) {
            backtrack(currStr + ')', n, leftCnt, rightCnt+1);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        backtrack(str, n, 0, 0);
        return ans;
    }
};