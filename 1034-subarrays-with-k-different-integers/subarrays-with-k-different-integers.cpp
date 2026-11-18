class Solution {
public:
    long long solve(vector<int>&nums ,int k){
        unordered_map<int,int>m;
        int start=0,end=0;
        long long total=0;
        for(end=0;end<nums.size();end++){
            m[nums[end]]++;
            while(m.size()>k){
                m[nums[start]]--;
                if(m[nums[start]]==0){
                    m.erase(nums[start]);
                }
                start++;
            }
            total+=end-start+1;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};