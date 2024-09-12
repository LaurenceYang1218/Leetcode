class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0; 
        for (string str : words) {
            bool flag = false;
            for (char c : str) {
                if (allowed.find(c) == string::npos) {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                cnt++;
        }
        return cnt;
    }
};