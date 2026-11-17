class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd=0,count=0,total=0;
        unordered_map<int ,int>m;
        m[0]=1;
        for(int i=0;i<nums.size();i++){
           if(nums[i]%2!=0) {
            odd++;
           }
        if (m.find(odd - k) != m.end()) {
                total += m[odd - k];
            }    
        m[odd]++;
        }
        return total;
    }
};