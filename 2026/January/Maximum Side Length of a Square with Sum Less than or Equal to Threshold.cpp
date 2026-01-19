class Solution {
public:
    int getSum(int i, int j, int k, vector<vector<int>>& ps) {
        return ps[i + k][j + k] - ps[i][j + k] - ps[i + k][j] + ps[i][j];
    }

    int findUsingBinarySearch(int i, int j,
                              vector<vector<int>>& ps,
                              int threshold) {

        int n = ps.size() - 1;
        int m = ps[0].size() - 1;

        int low = 1, high = min(n - i, m - j);
        int side = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = getSum(i, j, mid, ps);

            if (sum <= threshold) {
                side = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return side;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();

        
        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i + 1][j + 1] =
                    ps[i][j + 1] + ps[i + 1][j] - ps[i][j] + mat[i][j];
            }
        }

        int maxSideLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { 
                int k = findUsingBinarySearch(i, j, ps, threshold);
                maxSideLen = max(maxSideLen, k);
            }
        }
        return maxSideLen;
    }
};
