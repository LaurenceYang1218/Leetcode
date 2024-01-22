class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n+1) / 2, actualSum = 0;

        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); i++) {
            numMap[nums[i]]++;
            actualSum += nums[i];
        }
        vector<int> vec;
        int duplicateNum = 0, missingNum = 0;
        for (auto it = numMap.begin(); it != numMap.end(); it++) { 
            cout << it->first << " " << it->second << '\n';
            if (it->second != 1) {
                duplicateNum = it->first;
                vec.push_back(duplicateNum);
                break;
            }
        }   
        missingNum = (expectedSum - (actualSum - duplicateNum));
        vec.push_back(missingNum);
        return vec;
    }
};