class Solution {
public:

    vector<int> diffWaysToCompute(string expression) {
        vector<int> ret;
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
        return ret;
    }
};