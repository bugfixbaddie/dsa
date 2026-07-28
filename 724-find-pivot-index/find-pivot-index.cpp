class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        int total = nums[n - 1];

        for (int i = 0; i < n; i++) {
            int left, right;

            if (i == 0)
                left = 0;
            else
                left = nums[i - 1];

            right = total - nums[i];

            if (left == right)
                return i;
        }

        return -1;
    }
};