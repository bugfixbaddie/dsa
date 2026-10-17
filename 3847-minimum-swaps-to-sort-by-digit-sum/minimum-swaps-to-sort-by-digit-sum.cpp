class Solution {
public:
    int minSwaps(vector<int>& nums) {
        auto sum = [](int x) {
            int s = 0;
            while (x) {
                s += x % 10;
                x /= 10;
            }
            return s;
        };
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int sa = sum(a), sb = sum(b);
            if (sa != sb) return sa < sb;
            return a < b;
        });
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[sorted[i]] = i;
        vector<bool> visited(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cycles++;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = pos[nums[j]];
                }
            }
        }
        return n - cycles;
    }
};