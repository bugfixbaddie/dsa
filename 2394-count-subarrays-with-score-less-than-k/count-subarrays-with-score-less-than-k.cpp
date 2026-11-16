class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int left=0;
        int right=0;
        long long sum=0;
        long long total=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(left<=right && sum*(right-left+1)>=k  ){
                sum-=nums[left];
                left++;
            }
            total+=right-left+1;
        }
        return total;
    }
};