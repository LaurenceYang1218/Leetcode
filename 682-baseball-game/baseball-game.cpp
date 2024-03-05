class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> records;
        for (int i = 0; i < operations.size(); i++) {
            long val;

            if ((val = strtol(operations[i].c_str(), NULL, 10)) != 0) {
                records.push_back(val);
            }else if (operations[i] == "C") {
                records.pop_back();
            }else if (operations[i] == "D") {
                int num = 2 * records.back();
                records.push_back(num);
            }else if (operations[i] == "+") {
                int n = records.size();
                records.push_back(records[n-2] + records[n-1]);
            }
        }
        int sum = 0;
        for (int i = 0; i < records.size(); i++) {
            sum += records[i];
        }
        return sum;
    }
};