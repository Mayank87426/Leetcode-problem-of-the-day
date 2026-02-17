class Solution {
public:
    string findTime(vector<int>& hrs, vector<int>& minutes) {
        int hours = 0, min = 0;

        for (int i = 0; i < 4; i++)
            if (hrs[i]) hours += (1 << i);

        for (int i = 0; i < 6; i++)
            if (minutes[i]) min += (1 << i);

        if (hours >= 12 || min >= 60) return "";

        string time = to_string(hours) + ":";
        if (min < 10) time += "0";
        time += to_string(min);

        return time;
    }

    void solve(int n, int idx,
               vector<int>& hrs,
               vector<int>& minutes,
               vector<string>& ans) {

        if (n == 0) {
            string time = findTime(hrs, minutes);
            if (time != "") ans.push_back(time);
            return;
        }

        for (int i = idx; i < 10; i++) {
            if (i < 4) {  
                if (hrs[i] == 0) {
                    hrs[i] = 1;
                    solve(n - 1, i + 1, hrs, minutes, ans);
                    hrs[i] = 0;
                }
            } else {      
                int j = i - 4;
                if (minutes[j] == 0) {
                    minutes[j] = 1;
                    solve(n - 1, i + 1, hrs, minutes, ans);
                    minutes[j] = 0;
                }
            }
        }
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<int> h(4, 0), m(6, 0);
        vector<string> ans;

        solve(turnedOn, 0, h, m, ans);

        return ans;
    }
};
