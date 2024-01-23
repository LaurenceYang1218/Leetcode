class Solution {
public:

    bool checkDuplicateCharacters(string str) {
        bool chars[256] = {false};
        for (int i = 0; i < str.length(); i++) {
            if (chars[static_cast<int>(str[i])])
                return true;
            else
                chars[static_cast<int>(str[i])] = true;
        }
        return false;
    }

    int maxLength(vector<string>& arr) {
        int ans = 0;
        vector<string> strVec;
        strVec.push_back("");
        
        for (int i = 0; i < arr.size(); i++) {
            string str = arr[i];
            for (int j = 0; j < strVec.size(); j++) {
                string newStr = str + strVec[j];
                if(!checkDuplicateCharacters(newStr))
                    strVec.push_back(newStr);
            }
        }
        
        for (int i = 0; i < strVec.size(); i++) {
            ans = max(ans, static_cast<int>(strVec[i].length()));
        }

        return ans;
    }
};