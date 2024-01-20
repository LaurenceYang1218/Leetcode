class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, ans = 0;
        while (i < chars.size()) {
            int groupLen = 1;
            while (i + groupLen < chars.size() && chars[i + groupLen] == chars[i]) {
                groupLen++;
            }
            chars[ans++] = chars[i];
            if (groupLen != 1) {
                string groupLenStr = to_string(groupLen);
                for (int j = 0; j < groupLenStr.length(); j++) {
                    chars[ans++] = groupLenStr[j];
                }    
            }
            i += groupLen;
        }
        return ans;
    }
};