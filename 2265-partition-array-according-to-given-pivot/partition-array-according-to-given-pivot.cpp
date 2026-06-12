class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       vector<int>less,high,equal;
       for(int i=0;i<nums.size();i++){
        if(nums[i]<pivot){
            less.push_back(nums[i]);
        }else if(nums[i]==pivot){
            equal.push_back(nums[i]);
        }else{
            high.push_back(nums[i]);
        }
       }
       vector<int>result;
       for (int num : less) result.push_back(num);   
       for (int num : equal) result.push_back(num);   
       for (int num : high) result.push_back(num);    


     return result;  
    }
};