class Solution {
public:
    double average(vector<int>& salary) {
        auto maxIt = max_element(salary.begin(), salary.end());
        salary.erase(maxIt);
        auto minIt = min_element(salary.begin(), salary.end());
        salary.erase(minIt);
        double avgSalary = 0.f;
        int n = salary.size();
        for (int i = 0; i < n; i++) {
            avgSalary += salary[i];
        }
        return avgSalary / n;
    }
};