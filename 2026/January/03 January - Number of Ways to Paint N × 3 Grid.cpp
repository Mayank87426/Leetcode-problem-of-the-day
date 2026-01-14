class Solution {
public:
    vector<vector<int>> dp;
    vector<string> states;
    const int MOD = 1e9 + 7;

    void generateStates(string cur, int len, char prev) {
        if (len == 0) {
            states.push_back(cur);
            return;
        }
        for (char c : {'R','G','B'}) {
            if (c == prev) continue;
            generateStates(cur + c, len - 1, c);
        }
    }

    int solve(int row, int prev) {
        if (row == 0) return 1;
        if (dp[row][prev] != -1) return dp[row][prev];

        long long ans = 0;
        for (int i = 0; i < states.size(); i++) {
            bool ok = true;
            for (int c = 0; c < 3; c++) {
                if (states[i][c] == states[prev][c]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                ans = (ans + solve(row - 1, i)) % MOD;
        }
        return dp[row][prev] = ans;
    }

    int numOfWays(int n) {
        generateStates("", 3, '#'); 
        int m = states.size();
        dp.assign(n, vector<int>(m, -1));

        long long res = 0;
        for (int i = 0; i < m; i++) {
            res = (res + solve(n - 1, i)) % MOD;
        }
        return res;
    }
};
