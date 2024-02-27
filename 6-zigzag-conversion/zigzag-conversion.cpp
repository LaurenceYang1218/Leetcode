class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int n = s.size();
        int numSections = ceil(n / (2 * numRows - 2.0));
        int numCols = numSections * (numRows-1);
        vector<vector<char>> mat(numRows, vector<char>(numCols, ' '));
        int currRow = 0, currCol = 0, currStrIdx = 0;
        while(currStrIdx < n) {
            while (currRow < numRows && currStrIdx < n) {
                mat[currRow][currCol] = s[currStrIdx];
                currRow++;
                currStrIdx++;
            }
            currRow -= 2;
            currCol++;
            while (currRow > 0 && currStrIdx < n) {
                mat[currRow][currCol] = s[currStrIdx];
                currRow--;
                currCol++;
                currStrIdx++;
            }
        }
        string ans = "";
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] != ' ') {
                    ans += mat[i][j];
                }
            }
        }
        return ans;
    }
};