class Solution {
public:
    string decodeString(string s) {
        stack<int> numSt;
        stack<string> strSt;
        int k = 0; 
        string currStr = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[') {
                numSt.push(k);
                strSt.push(currStr);
                currStr = "";
                k = 0;
            }else if (s[i] == ']') {
                string decodeStr = strSt.top();
                strSt.pop();
                for (int i = 0; i < numSt.top(); i++) {
                    decodeStr = decodeStr + currStr;
                }
                numSt.pop();
                currStr = decodeStr;
            }else if (isdigit(s[i])) {
                k = k * 10 + (s[i] - '0');
            }else {
                currStr = currStr + s[i];
            }
        }
        return currStr;
    }
};