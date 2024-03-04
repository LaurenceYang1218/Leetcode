class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int left = 0, right = tokens.size()-1;
        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left++];
                score++;
                maxScore = max(maxScore, score);
            }else if (score > 0) {
                power += tokens[right--];
                score--;
            }else {
                break;
            }
        }
        return maxScore;
    }
};