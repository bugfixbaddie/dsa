class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxe=0;
           long long total=0;
        for(int i=0;i<nums.size();i++){
            maxe=max(maxe,nums[i]);
        }
            int count=0,n=nums.size();
            int start=0,end=0;
            while(end<nums.size()){
                if(nums[end]==maxe)
                count++;
                while(count>=k){
                    total+=n-end;
                    if(nums[start]==maxe)
                    count--;
                    start++;
                }
                end++;
            
        } return total;
    }
};