
class Solution {
public:
    void solve(vector<vector<long long>>& grid) {
        for (int via = 0; via < 26; ++via) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (grid[i][via] != LLONG_MAX && grid[via][j] != LLONG_MAX) {
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target,
                          vector<char>& original, vector<char>& changed,
                          vector<int>& cost) {
        if (source.length() != target.length()) return -1;

        vector<vector<long long>> grid(26, vector<long long>(26, LLONG_MAX));

        for (int i = 0; i < 26; ++i) {
            grid[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            grid[u][v] = min(grid[u][v], (long long)cost[i]);
        }

        solve(grid);

        long long ans = 0;
        for (int i = 0; i < source.length(); ++i) {
            if (source[i] == target[i]) continue;

            int from = source[i] - 'a';
            int to = target[i] - 'a';

            if (grid[from][to] == LLONG_MAX) return -1;
            ans += grid[from][to];
        }

        return ans;
    }
};
