class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        vector<int> altitudes(gain.size()+1, 0);
        for (int i = 1; i <= gain.size(); i++) {
            altitudes[i] = altitudes[i-1] + gain[i-1]; 
        }
        ans = *max_element(altitudes.begin(), altitudes.end());
        return ans;
    }
};