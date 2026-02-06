class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        int minRemovals = n - 1;
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(begin(nums), end(nums), 1LL*k * nums[i]);
            it--;
            int idx = it - nums.begin();
            if (idx < 0)
                continue;
            int removals = i + n - idx-1;
            minRemovals = min(minRemovals, removals);
        }
        return minRemovals;
    }
};
