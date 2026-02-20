class Solution {
public:
    string solve(string s) {
        if (s == "")
            return "";
        vector<string> specials;
        int n = s.length(), start = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (s[i] == '1' ? 1 : -1);
            if (sum == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                string res = '1' + solve(inner) + '0';
                specials.push_back(res);
                start = i + 1;
            }
        }
        string sp = "";
        sort(begin(specials), end(specials), greater<string>());
        for (auto x : specials)
            sp += x;
        cout << sp << endl;
        return sp;
    }
    string makeLargestSpecial(string s) { return solve(s); }
};
