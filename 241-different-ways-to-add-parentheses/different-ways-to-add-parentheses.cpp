class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                vector<int> leftResult = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResult = diffWaysToCompute(expression.substr(i+1));
                for (auto leftRes : leftResult) {   
                    for (auto rightRes : rightResult) {
                        switch(expression[i]) {
                        case '+':
                            ret.push_back(leftRes + rightRes);
                            break;
                        case '-':
                            ret.push_back(leftRes - rightRes);
                            break;
                        case '*':
                            ret.push_back(leftRes * rightRes);
                            break;
                        default:
                            return ret;
                            break;
                        }
                    }
                }
            }   
        }
        if (ret.empty()) {
            ret.push_back(stoi(expression));
        }
        memo[expression] = ret;
        return ret;
    }
};