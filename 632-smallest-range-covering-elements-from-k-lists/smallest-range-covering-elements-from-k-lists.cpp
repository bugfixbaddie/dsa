
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //created min heap priority q where value row col
        priority_queue<
            pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p;
        int mini, maxi = INT_MIN;
       // insert 1st lelement of each row
        for(int i = 0; i < nums.size(); i++) {
         p.push({nums[i][0], {i, 0}});
          maxi = max(maxi, nums[i][0]);
        }
        // 1st min element from heap
        mini = p.top().first;
        // Store initial range
        vector<int> ans = {mini, maxi};
        pair<int,pair<int,int>> temp;
        int row, col, element;
        while(p.size() == nums.size()) {
            temp = p.top();
            p.pop();
            element = temp.first;
            row = temp.second.first;
            col = temp.second.second;
            if(col + 1 < nums[row].size()) {
                col++;
                // Insert next element from same row
                p.push({nums[row][col], {row, col}});
                // Update maximum
                maxi = max(maxi, nums[row][col]);
                // Current minimum
                mini = p.top().first;
                // Check if current range is smaller
                if(maxi - mini < ans[1] - ans[0]) {
                    ans[0] = mini;
                    ans[1] = maxi;
                }
            }
            else {
                break;
            }
        }
        return ans;
    }
};
