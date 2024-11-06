class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (!pq.empty()) {
            if (pq.size() == 1) {
                break;
            }
            int st1 = pq.top(); pq.pop();
            int st2 = pq.top(); pq.pop();
            if (st1 != st2) {
                pq.push(st1 - st2);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};