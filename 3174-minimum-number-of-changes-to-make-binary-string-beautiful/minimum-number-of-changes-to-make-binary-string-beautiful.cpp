class Solution {
public:
    int minChanges(string s) {
        vector<string> strvec;
        for (int i = 0; i < s.length(); i += 2) {
            strvec.push_back(s.substr(i, 2));
        }
        int cnt = 0;
        for (auto it : strvec) {
            int bit1 = it[0] - '0', bit0 = it[1] - '0';
            if (bit1 ^ bit0) {
                cnt++;
            }
        }
        return cnt;
    }
};