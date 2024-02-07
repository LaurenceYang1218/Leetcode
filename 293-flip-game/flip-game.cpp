class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> ans;
        if (currentState.length() < 2) {
            return ans;
        }
        for (int i = 0; i < currentState.length()-1; i++) {
            string nextState;
            if (currentState[i] == '+' && currentState[i+1] == '+') {
                nextState = currentState.substr(0, i) + "--" + currentState.substr(i+2);
                ans.push_back(nextState);
            }
            
        }
        return ans;
    }
};