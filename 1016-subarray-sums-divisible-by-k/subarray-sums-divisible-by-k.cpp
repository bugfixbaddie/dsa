class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int sum=0;
        unordered_map<int,int>m;
        m[0]=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
           int rem = ((sum % k) + k) % k;
             total += m[rem];
            m[rem]++;
        }
        return total;
    }
};