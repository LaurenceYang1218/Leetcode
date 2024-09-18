class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (size_t i = 0; i < nums.size(); i++) {
            strs.push_back(to_string(nums[i]));
        }

        sort(strs.begin(), strs.end(), [](string& a, string& b) {
            return a + b > b + a;
        });
        
        if (strs[0] == "0") {
            return "0";
        }
        string ret;
        for (auto it : strs) {
            ret += it;
        }
        return ret;
    }
};