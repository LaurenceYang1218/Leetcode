class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> startBit(start);
        bitset<32> goalBit(goal);

        string str = (startBit ^ goalBit).to_string();
        int cnt = 0;
        for (char c : str) {
            if (c == '1') 
                cnt++;
        }
        return cnt;
    }
};