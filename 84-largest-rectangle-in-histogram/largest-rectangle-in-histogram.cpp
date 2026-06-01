class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // next smallest left
        // next smallest right
        int n=heights.size();
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;
        // next smallest right
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            right[st.top()]=n;
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
           while(!st.empty()&& heights[st.top()]>=heights[i]){
             left[st.top()]=i;
                st.pop();
           }
           st.push(i);
        }
         while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }
        // area calculate 
        int ans=0;
        for(int i=0;i<n;i++){
         
         ans=max(ans,heights[i]*(right[i]-left[i]-1));

        }
        return ans;
    }
};