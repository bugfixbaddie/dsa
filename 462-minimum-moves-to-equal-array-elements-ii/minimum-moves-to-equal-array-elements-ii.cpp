class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=nums[nums.size()/2];
        long long steps=0;
        for(int n:nums){
            steps+=abs(n-mid);
        }
        return steps;
    }
};