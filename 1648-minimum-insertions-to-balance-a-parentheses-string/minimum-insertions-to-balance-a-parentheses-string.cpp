class Solution {
public:
    int minInsertions(string s) {
      int close= 0;
        int insert = 0;
          for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                close += 2;
                if (close % 2 == 1) {
                    insert++;
                    close--;
                }
            } else {
                close--;
                if (close < 0) {
                    insert++;
                    close= 1;
                }
            }
        }
           return insert + close;
    }
};