class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // Remove expired flips
            if (!q.empty() && q.front() == i - k)
                q.pop();

            // Check current effective bit
            int bit = nums[i];

            if (q.size() % 2 == 1)
                bit = 1 - bit;

            // If bit is 0, we must flip
            if (bit == 0) {

                // Not enough elements to flip
                if (i + k > n)
                    return -1;

                ans++;

                // Remember this flip
                q.push(i);
            }
        }

        return ans;
    }
};