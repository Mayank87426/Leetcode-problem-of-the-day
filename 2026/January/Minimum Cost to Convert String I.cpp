class Solution {
public:
    void flloydWarshall(vector<char>& original, vector<char>& changed,
                        vector<vector<int>>& grid) {
        int n = original.size();
        for (char via = 'a'; via <= 'z'; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[original[i] - 'a'][via - 'a'] == INT_MAX ||
                        grid[via - 'a'][changed[j] - 'a'] == INT_MAX)
                        continue;
                    grid[original[i] - 'a'][changed[j] - 'a'] =
                        min(grid[original[i] - 'a'][changed[j] - 'a'],
                            grid[original[i] - 'a'][via - 'a'] +
                                grid[via - 'a'][changed[j] - 'a']);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        int n = original.size();

        vector<vector<int>> grid(26, vector<int>(26, INT_MAX));
        for (int i = 0; i < n; i++) {
            grid[original[i] - 'a'][changed[i] - 'a'] =
                min(cost[i], grid[original[i] - 'a'][changed[i] - 'a']);
        }
        flloydWarshall(original, changed, grid);
        long long totalCost = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i])
                continue;
            totalCost += grid[source[i] - 'a'][target[i] - 'a'];
        }
        return totalCost>=INT_MAX?-1:totalCost;
    }
};
