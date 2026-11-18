class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if (t.size() > n) return "";
        vector<int> freq(128, 0);
        for (char c : t) {
        freq[c]++;
        }
        int left = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;
        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (freq[c] > 0) {
                required--;
            }
            freq[c]--;
            while (required == 0) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    start = left;
                }
                char ch = s[left];
                freq[ch]++;
                if (freq[ch] > 0) {
                    required++;
                }
                left++;
            }
        }
        if (minLen == INT_MAX)
            return "";
        return s.substr(start, minLen);
    }
};