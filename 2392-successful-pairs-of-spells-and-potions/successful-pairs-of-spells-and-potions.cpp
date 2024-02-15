class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        int n = spells.size(), m = potions.size();
        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            long long target = success % spell ? success / spell + 1 : success / spell;
            int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
            ans.push_back(m - idx);
        }
        return ans;
    }
};