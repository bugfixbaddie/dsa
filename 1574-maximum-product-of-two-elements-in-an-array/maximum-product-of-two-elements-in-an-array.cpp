#include<math.h>
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxx=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxx=max((nums[i]-1)* (nums[j]-1),maxx);
            }
        }
        return maxx;
        
    }
};