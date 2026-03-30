class Solution {
public:
void permut(vector<int>&arr,vector<vector<int>>&ans,vector<int>&temp,vector<bool>&visited)
{
    if(visited.size()==temp.size()){
        ans.push_back(temp);
        return;
    }
     for(int i=0;i<visited.size();i++){
         if (visited[i]) continue;

            //  Skip duplicates
            if (i > 0 && arr[i] == arr[i-1] && !visited[i-1])
                continue;

            visited[i] = 1;
            temp.push_back(arr[i]);

            permut(arr, ans, temp, visited);

            temp.pop_back();
            visited[i] = 0;
      }  
}
    vector<vector<int>> permuteUnique(vector<int>&arr) {
         vector<vector<int>>ans;
    vector<int>temp;
    vector<bool>visited(arr.size(),0);
    sort(arr.begin(),arr.end());
    permut(arr,ans,temp,visited);
    return ans;
    }
};