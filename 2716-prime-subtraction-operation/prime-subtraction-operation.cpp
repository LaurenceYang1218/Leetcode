class Solution {
public:
    bool isPrime(int num) {
        int end = (int)sqrt(num);
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= end; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(vector<int>& nums) {
        int maxPrime = *max_element(nums.begin(), nums.end());
        int currIdx = 0, currValue = 1;
        while (currIdx < nums.size()) {
            int diff = nums[currIdx] - currValue;
            if (diff < 0) {
                return false;
            }
            if (diff == 0 || isPrime(diff)) {
                currIdx++;
                currValue++;
            }else {
                currValue++;
            }
        }
        return true;
    }
};