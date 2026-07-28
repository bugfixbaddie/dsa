class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        for (int pivot = 0; pivot < n; pivot++) {

            int leftSum = 0;
            int rightSum = 0;

            
            for (int i = 0; i < pivot; i++) {
                leftSum += nums[i];
            }

            
            for (int i = pivot + 1; i < n; i++) {
                rightSum += nums[i];
            }

            if (leftSum == rightSum)
                return pivot;
        }

        return -1;
    }
};