class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rQueue, dQueue;
        for (int i = 0; i < senate.length(); i++) {
            if (senate[i] == 'R') {
                rQueue.push(i);
            }else if (senate[i] == 'D') {
                dQueue.push(i);
            }
        }
        while (!rQueue.empty() && !dQueue.empty()) {
            int rTurn = rQueue.front();
            rQueue.pop();
            int dTurn = dQueue.front();
            dQueue.pop();
            if (dTurn < rTurn) {
                dQueue.push(dTurn + senate.length());
            }else {
                rQueue.push(rTurn + senate.length());
            }   
        }
        return rQueue.empty() ? "Dire" : "Radiant";
    }
};