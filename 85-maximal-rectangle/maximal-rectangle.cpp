class Solution {
public:

    // Function to find largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> left(n);   // nearest smaller on left
        vector<int> right(n);  // nearest smaller on right

        stack<int> st;

        // -------------------------
        // Find Next Smaller Right
        // -------------------------
        for(int i = 0; i < n; i++) {

            while(!st.empty() &&
                  heights[st.top()] > heights[i]) {

                right[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // No smaller element on right
        while(!st.empty()) {
            right[st.top()] = n;
            st.pop();
        }

        // -------------------------
        // Find Next Smaller Left
        // -------------------------
        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() &&
                  heights[st.top()] > heights[i]) {

                left[st.top()] = i;
                st.pop();
            }

            st.push(i);
        }

        // No smaller element on left
        while(!st.empty()) {
            left[st.top()] = -1;
            st.pop();
        }

        // -------------------------
        // Calculate Area
        // -------------------------
        int maxArea = 0;

        for(int i = 0; i < n; i++) {

            int width = right[i] - left[i] - 1;

            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {

        // Edge case
        if(matrix.empty())
            return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int ans = 0;

        // Histogram heights
        vector<int> heights(cols, 0);

        // Process row by row
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                // If current cell is 0,
                // rectangle breaks
                if(matrix[i][j] == '0')
                    heights[j] = 0;

                // If current cell is 1,
                // increase height
                else
                    heights[j]++;
            }

            // Find largest histogram area
            ans = max(ans,
                     largestRectangleArea(heights));
        }

        return ans;
    }
};