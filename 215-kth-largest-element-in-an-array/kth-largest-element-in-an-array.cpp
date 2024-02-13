class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int ans = 0, i = 0;
        while (i < k) {
            if (i == k-1) {
                ans = pq.top();
            }
            pq.pop();
            i++;
        }
        return ans;
    }
};