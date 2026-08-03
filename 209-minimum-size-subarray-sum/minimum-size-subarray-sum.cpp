class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int start = 0;
        int end = 0;
        int currentSum = 0;
        int result = INT_MAX;

        for (end = 0; end < nums.size(); end++) {

            // Add current element to window
            currentSum += nums[end];

            // If sum is >= target, try shrinking the window
            while (currentSum >= target) {

                // Calculate current window length
                result = min(result, end - start + 1);

                // Remove leftmost element
                currentSum -= nums[start];

                // Move start forward
                start++;
            }
        }

        // If no valid subarray was found
        return result == INT_MAX ? 0 : result;
    }
};