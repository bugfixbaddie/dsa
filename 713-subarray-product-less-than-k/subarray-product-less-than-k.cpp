class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        long long  prod=1;
        int total=0;
        int left=0,right=0;
        unordered_map<int,int>m;
        for(int right=0;right<n;right++){
            prod*=nums[right];
            while(left<=right && prod>=k){
                prod/=nums[left];
                left++;
            }
             total+=right-left+1;
        }
        return total;
    }
};