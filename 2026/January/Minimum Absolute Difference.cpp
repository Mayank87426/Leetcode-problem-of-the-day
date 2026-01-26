class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr), end(arr));
        vector<vector<int>> ans;
        int n = arr.size(), minAbs = INT_MAX;
        for (int i = 1; i < n; i++) {
            minAbs = min(minAbs, abs(arr[i] - arr[i - 1]));
        }
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) == minAbs) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};
