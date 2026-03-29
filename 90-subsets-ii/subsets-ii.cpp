class Solution {
public:
   void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int index){
    ans.push_back(curr);
    for(int i=index;i<nums.size();i++){
        if(i>index && nums[i]==nums[i-1]) continue;
        curr.push_back(nums[i]);
        solve(nums,ans,curr,i+1);
        curr.pop_back();
    }
   }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        solve(nums,ans,curr,0);
        return ans;
    }
};