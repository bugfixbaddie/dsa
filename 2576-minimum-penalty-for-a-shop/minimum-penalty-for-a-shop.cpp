class Solution {
public:
    int bestClosingTime(string customers) {
         int maxscore = 0, score = 0, besthr = -1;
        for(int i = 0; i < customers.size(); ++i) {
            score += (customers[i] == 'Y') ? 1 : -1;
            if(score > maxscore) {
                maxscore = score;
                besthr = i;
            }
        }
        return besthr + 1;
    }
};