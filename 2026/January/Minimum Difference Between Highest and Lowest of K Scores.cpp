class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1)
            return 0;
        int n = nums.size();
        int minScore = INT_MAX;
        sort(begin(nums), end(nums));
        for (int i = 0; i <= n - k; i++) {
            minScore = min(minScore, nums[i + k - 1] - nums[i]);
        }
        return minScore;
    }
};
