class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        vector<vector<int>>answer;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int result=nums[i]+nums[j]+nums[k];
                if(result==sum){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                }else if(result<sum){
                    j++;
                }else{
                    k--;
                }
            }
        }
        for(auto solution:s)
           answer.push_back(solution);
           return answer;
    }
};