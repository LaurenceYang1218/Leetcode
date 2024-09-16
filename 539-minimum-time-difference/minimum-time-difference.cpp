class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minute;
        for (int i = 0; i < timePoints.size(); i++) {
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));
            minute.push_back(h * 60 + m);
        }
        sort(minute.begin(), minute.end());
        minute.push_back(*minute.begin()+24 * 60);
        int ret = INT_MAX; 
        for (int i = 1; i < minute.size(); i++) {
            ret = min(ret, minute[i] - minute[i-1]);
        }
        return ret;
    }
};