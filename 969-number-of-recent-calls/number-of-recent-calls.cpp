class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }
    
    int ping(int t) {
        int start = t-3000, end = t;
        while(!q.empty()) {
            if (q.front() < start) {
                q.pop();
            }else {
                break;
            }
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */