class MyCalendar {
public:
    vector<pair<int, int>> dates;
    MyCalendar() {
        
    }

    inline bool isOverlaped(pair<int, int> p1, pair<int, int> p2) {
        return max(p1.first, p2.first) < min(p1.second, p2.second);
    }

    bool book(int start, int end) {
        for (auto it : dates) {
            // if (start < it.second && end > it.first) {
            if (isOverlaped(it, {start, end})) {
                return false;
            }
        }
        dates.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */