class Solution {
public:
    void construct(vector<string>& strVec, string currStr, int curr, int n) {
        if (curr == n) {
            return;
        }
        string invCurrStr = "";
        for (int i = 0; i < currStr.length(); i++) {
            if (currStr[i] == '1')
                invCurrStr += '0';
            else
                invCurrStr += '1';
        }
        reverse(invCurrStr.begin(), invCurrStr.end());
        string newStr = currStr + "1" + invCurrStr;
        strVec.push_back(newStr);
        construct(strVec, newStr, curr+1, n);
        return;
    }

    char findKthBit(int n, int k) {
        vector<string> strVec;
        strVec.push_back("0");
        construct(strVec, "0", 1, n);    
        return strVec[n-1][k-1];
    }
};