class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        string str = "123456789";
        int lowLen = to_string(low).length();
        int highLen = to_string(high).length();

        for (int i = lowLen; i < highLen+1; i++) {
            for (int j = 0; j < 10-i; j++) {
                int intStr = stoi(str.substr(j, i));
                if (intStr >= low && intStr <= high) {
                    ans.push_back(intStr);
                }
            } 
        }
        
        return ans;
    }
};