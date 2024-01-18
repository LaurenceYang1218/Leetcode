class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> strVec;
        
        string str, ans;
        while (ss >> str) {
            strVec.push_back(str);
        }
        
        for (int i = strVec.size()-1; i > 0; i--) {
            ans += (strVec[i] + " ");
        }
        ans += strVec[0];
        return ans;
    }   
};