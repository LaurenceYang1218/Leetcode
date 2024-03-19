class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) 
                pq.push(freq[i]);
        }
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> tempFreq;
            int taskCnt = 0;
            while (cycle > 0 && !pq.empty()) {
                if (pq.top() > 1)
                    tempFreq.push_back(pq.top()-1);
                pq.pop();
                taskCnt++;
                cycle--;
            }

            for (int i = 0; i < tempFreq.size(); i++) {
                pq.push(tempFreq[i]);
            }

            ans += (pq.empty() ? taskCnt : n+1);
        }
        return ans;
    }
};