class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int count = 0;
        int minVal = INT_MAX;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                minVal = min(minVal, abs(matrix[i][j]));
                if (matrix[i][j] < 0)
                    count++;
                sum += abs(matrix[i][j]);
            }
        }
        return count % 2 == 0 ? sum : sum - 2LL * minVal;
    }
};
