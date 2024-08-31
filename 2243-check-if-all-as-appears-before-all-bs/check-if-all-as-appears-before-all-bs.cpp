class Solution {
public:
    bool checkString(string s) {
        if (s.find('a') == string::npos) {
            return true;
        }
        int lastA = s.find_last_of('a');
        for (int i = 0; i < lastA; i++) {
            if (s[i] == 'b') {
                return false;
            }
        }
        return true;
    }
};