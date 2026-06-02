class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // This variable remembers whether
        // the FIRST COLUMN needs to become zero.
        //
        // Why?
        // Because matrix[0][0] is shared by:
        // - first row marker
        // - first column marker
        //
        // One cell cannot store both.
        int col0 = 1;

        // ===================================================
        // PASS 1: MARK ROWS AND COLUMNS THAT NEED TO BE ZERO
        // ===================================================

        for(int i = 0; i < rows; i++) {

            // If any element in first column is zero,
            // remember that first column must be zero later.
            if(matrix[i][0] == 0)
                col0 = 0;

            // Start from column 1 because column 0
            // is being used as row-marker storage.
            for(int j = 1; j < cols; j++) {

                // Found a zero
                if(matrix[i][j] == 0) {

                    // Mark the ENTIRE ROW
                    matrix[i][0] = 0;

                    // Mark the ENTIRE COLUMN
                    matrix[0][j] = 0;
                }
            }
        }

        // ===================================================
        // PASS 2: FILL ZEROS USING THE MARKERS
        // ===================================================
        //
        // Traverse from bottom-right.
        //
        // Reason:
        // We don't want to destroy markers
        // in first row/column before using them.
        //
        for(int i = rows - 1; i >= 0; i--) {

            for(int j = cols - 1; j >= 1; j--) {

                // If row OR column is marked,
                // make this cell zero.
                if(matrix[i][0] == 0 ||
                   matrix[0][j] == 0) {

                    matrix[i][j] = 0;
                }
            }

            // Handle first column separately
            // using col0 variable.
            if(col0 == 0)
                matrix[i][0] = 0;
        }
    }
};