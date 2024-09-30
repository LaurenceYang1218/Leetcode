class CustomStack {
public:
    vector<int> st;
    int cnt;
    int maxSize;
    CustomStack(int maxSize) {
        st = vector<int>(maxSize, 0);
        this->cnt = 0;
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (cnt < maxSize)
            st[cnt++] = x;
        return;
    }
    
    int pop() {
        int ret = -1;
        if (cnt > 0) {
            ret = st[--cnt];
        }
        return ret;
    }
    
    void increment(int k, int val) {
        int numIncrease = (cnt > k) ? k : cnt;
        for (int i = 0; i < numIncrease; i++) {
            st[i] += val;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */