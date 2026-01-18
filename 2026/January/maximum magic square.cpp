class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxK = 1;

        for (int k = 1; k <= min(m, n); k++) {
            for (int r = 0; r <= m - k; r++) {
                for (int c = 0; c <= n - k; c++) {
                    if (isMagic(grid, r, c, k)) {
                        maxK = max(maxK, k);
                    }
                }
            }
        }
        return maxK;
    }

    bool isMagic(const vector<vector<int>>& grid, int r, int c, int k) {
        int targetSum = 0;

        // Sum of first row
        for (int j = c; j < c + k; j++) {
            targetSum += grid[r][j];
        }

        // Check rows
        for (int i = r + 1; i < r + k; i++) {
            int rowSum = 0;
            for (int j = c; j < c + k; j++) {
                rowSum += grid[i][j];
            }
            if (rowSum != targetSum) return false;
        }

        // Check columns
        for (int j = c; j < c + k; j++) {
            int colSum = 0;
            for (int i = r; i < r + k; i++) {
                colSum += grid[i][j];
            }
            if (colSum != targetSum) return false;
        }

        // Check main diagonal
        int diag1 = 0;
        for (int i = 0; i < k; i++) {
            diag1 += grid[r + i][c + i];
        }
        if (diag1 != targetSum) return false;

        // Check anti diagonal
        int diag2 = 0;
        for (int i = 0; i < k; i++) {
            diag2 += grid[r + i][c + k - 1 - i];
        }
        if (diag2 != targetSum) return false;

        return true;
    }
};
