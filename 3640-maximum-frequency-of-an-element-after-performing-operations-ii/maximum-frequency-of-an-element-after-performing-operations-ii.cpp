class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<pair<int, int>> events;
        unordered_map<int, int> freq;
        set<int> points;
        for (auto num : nums) {
            freq[num]++;
            events.push_back({num-k, 1});
            events.push_back({num+k+1, -1});
            points.insert(num);
            points.insert(num-k);
            points.insert(num+k+1);
        }
        sort(events.begin(), events.end());
        int idx = 0, overlap = 0, ret = 0;
        for (auto p : points) {
            while (idx < events.size() && events[idx].first <= p) {
                overlap += events[idx].second;
                idx++;
            }
            int currFreq = freq.count(p) ? freq[p] : 0;
            int maxFreq = currFreq + min(numOperations, overlap - currFreq);
            ret = max(ret, maxFreq);
        }
        return ret;
    }
};