class Solution {
public:
    string divideCommonPrefix(vector<string> strs, int l, int r) {
        if (l == r) {
            return strs[l];
        }else {
            int mid = (l + r) / 2;
            string strLeft = divideCommonPrefix(strs, l, mid);
            string strRight = divideCommonPrefix(strs, mid+1, r);
            return conquerCommonPrefix(strLeft, strRight);
        }
    }
    
    string conquerCommonPrefix(string left, string right) {
        int minLen = min(left.length(), right.length());
        string ans = "";
        for (int i = 0; i < minLen; i++) {
            if (left[i] == right[i]) {
                ans += left[i];
            }else {
                break;
            }
        }
        return ans;
    }

    string longestCommonPrefix(vector<string>& strs) {
        return divideCommonPrefix(strs, 0, strs.size()-1);
    }
};