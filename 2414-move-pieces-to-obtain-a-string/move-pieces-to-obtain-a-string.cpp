class Solution {
public:
    bool canChange(string start, string target) {
        int len = start.length();
        int startIdx = 0, targetIdx = 0;
        while (startIdx < len || targetIdx < len) {
            while (startIdx < len && start[startIdx] == '_') {
                startIdx++;
            }
            while (targetIdx < len && target[targetIdx] == '_') {
                targetIdx++;
            }
            if (startIdx == len || targetIdx == len) {
                return startIdx == len && targetIdx == len;
            }
            if (start[startIdx] != target[targetIdx] || 
                (start[startIdx] == 'L' && startIdx < targetIdx) || 
                (start[startIdx] == 'R' && startIdx > targetIdx))
            {
                return false;
            }
            startIdx++;
            targetIdx++;
        }
        return true;
    }
};