class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            // remove elements outside the current window
            while(!d.empty() && d.front()<=i-k){
                d.pop_front();
            }
            // remove smaller elemnts
            while(!d.empty() && nums[d.back()]<=nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[d.front()]);
            }

        }
        return ans;
       
    }
};