class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<int> xorMap(26, 0);
        xorMap['a' - 'a'] = 1;
        xorMap['e' - 'a'] = 2;
        xorMap['i' - 'a'] = 4;
        xorMap['o' - 'a'] = 8;
        xorMap['u' - 'a'] = 16;

        int prefixXOR = 0, ret = 0;
        vector<int> xorTable(32, -1);
        for (int i = 0; i < s.length(); i++) {
            prefixXOR ^= xorMap[s[i] - 'a'];
            cout << prefixXOR << endl;
            if (prefixXOR != 0 && xorTable[prefixXOR] == -1) {
                xorTable[prefixXOR] = i;
            }
            ret = max(ret, i - xorTable[prefixXOR]);
        }   
        return ret;
    }
};