class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> vec(candies.size(), false);
        int maxCandies = INT_MIN;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > maxCandies)
                maxCandies = candies[i];
        }
        for (int i = 0; i < candies.size(); i++) {
            vec[i] = (candies[i] + extraCandies >= maxCandies);
        }
        return vec;
    }
};