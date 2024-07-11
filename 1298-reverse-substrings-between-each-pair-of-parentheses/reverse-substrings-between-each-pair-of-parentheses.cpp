class Solution {
public:
    
    string reverseParentheses(string s) {
        string result = "";
        stack<char> st;
        stack<int> startIdx;
        int wordIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                startIdx.push(wordIdx);
            }else if (s[i] == ')') {
                st.pop();
                reverse(result.begin() + startIdx.top(), result.end());
                startIdx.pop();
            }else {
                wordIdx++;
                result += s[i];
            }
        }
        return result;
    }
};