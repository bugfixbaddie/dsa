class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sol=0;
        unordered_map<int,int>m;
        for(int i:nums){
            m[i+1]=max(m[i+1],m[i]+1);
            m[i]=max(m[i-1]+1,m[i]);
            sol=max({sol,m[i],m[i+1]});
        }
        return sol;
    }
};