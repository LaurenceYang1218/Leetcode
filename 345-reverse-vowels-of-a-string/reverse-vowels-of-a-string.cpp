class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        vector<int> vowelsPos;

        bool isUpperVowel, isLowerVowel;
        for (int i = 0; i < s.length(); i++) {
            isUpperVowel = (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U');
            isLowerVowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
            if (isUpperVowel || isLowerVowel) {
                vowels += s[i]; 
                vowelsPos.push_back(i);
            }
        }
        reverse(vowels.begin(), vowels.end());
        int vowelsCnt = 0;
        for (auto it = vowelsPos.begin(); it != vowelsPos.end(); it++) {
            s[*it] = vowels[vowelsCnt++];
        }
        return s;
    }
};