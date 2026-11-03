class Solution {
public:
    int minMoves(vector<int>& nums) {
    int m = *max_element(nums.begin(), nums.end());
     int steps = 0;
        for (int n : nums) {
            steps += m - n;
        }
  return steps;
    }
};