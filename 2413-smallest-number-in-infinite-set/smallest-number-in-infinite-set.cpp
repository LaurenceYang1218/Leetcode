class SmallestInfiniteSet {
public:
    unordered_set<int> infSet;
    priority_queue<int, vector<int>, greater<int>> pq;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            pq.push(i);
            infSet.insert(i);
        }
    }
    
    int popSmallest() {
        int ret = pq.top();
        infSet.erase(ret);
        pq.pop();
        return ret;
    }
    
    void addBack(int num) {
        if (infSet.find(num) == infSet.end()) {
            pq.push(num);
            infSet.insert(num);
        }
        return;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */