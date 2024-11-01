class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        if (s.length() == 0) {
            return 0;
        }
        st.push(-1);
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }else {
                    ret = max(ret, i - st.top());
                }
            }
        }
        return ret;
    }
};