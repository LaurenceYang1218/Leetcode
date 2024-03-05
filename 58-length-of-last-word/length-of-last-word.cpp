class Solution {
public:
    int lengthOfLastWord(string s) {
        int leftIdx = 0, rightIdx = s.length()-1;
        while (s[leftIdx] == ' ') {
            leftIdx++;
        }
        while(s[rightIdx] == ' ') {
            rightIdx--;
        } 
        string subs = s.substr(leftIdx, rightIdx-leftIdx+1);
        reverse(subs.begin(), subs.end());
        istringstream iss(subs);
        string ansStr;
        getline(iss, ansStr, ' ');

        return ansStr.length();
    }
};