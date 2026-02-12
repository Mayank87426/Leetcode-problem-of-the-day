class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), maxLen = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                int len = j - i + 1;
                if (len % mp.size() != 0)
                    continue;
                bool flag = true;
                for (auto [c, f] : mp) {
                    if (f != (len / mp.size())) {
                        flag = false;
                    }
                }
                if (flag)
                    maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
