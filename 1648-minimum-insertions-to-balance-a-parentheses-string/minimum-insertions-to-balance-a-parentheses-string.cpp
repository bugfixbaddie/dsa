class Solution {
public:
    int minInsertions(string s) {
      int closeNeeded = 0;
        int insertions = 0;
          for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                closeNeeded += 2;
                if (closeNeeded % 2 == 1) {
                    insertions++;
                    closeNeeded--;
                }
            } else {
                closeNeeded--;
                if (closeNeeded < 0) {
                    insertions++;
                    closeNeeded = 1;
                }
            }
        }
           return insertions + closeNeeded;
    }
};