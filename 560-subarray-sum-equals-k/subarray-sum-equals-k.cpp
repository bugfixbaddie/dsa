class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long int total=0;
        long long int prefixsum=0;
        unordered_map<long long int, int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            if(m.count(prefixsum-k)){
                total+=m[prefixsum-k];
            }
            
                m[prefixsum]++;
            
        }
        return total;
    }
};