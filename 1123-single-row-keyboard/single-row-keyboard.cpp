class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> keyMap;
        for (int i = 0; i < keyboard.length(); i++) {
            keyMap[keyboard[i]] = i;
        }
        int ans = keyMap[word[0]];
        for (int i = 1; i < word.length(); i++) {
            ans += abs(keyMap[word[i]] - keyMap[word[i-1]]);
        }
        return ans;
    }
};