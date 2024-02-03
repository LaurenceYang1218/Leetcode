class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '*') {
                st.push(s[i]);
            }else {
                st.pop();
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};