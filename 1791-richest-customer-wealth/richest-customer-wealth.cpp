class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(auto &i:accounts){
            int s=0;
            for(int j:i){
                s+=j;
            }
            ans=max(ans,s);
        }
        return ans;
    }
};