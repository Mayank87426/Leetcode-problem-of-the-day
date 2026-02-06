class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        for (int i = 0; i < n; i++) {
            if (!nums[i]) {
                result[i] = nums[i];
                continue;
            } else if (nums[i] > 0) {
                result[i] = nums[(i%n + nums[i]%n) % n];
            } else
                result[i] = nums[(i%n - abs(nums[i])%n+n) % n];
        }
        return result;
    }
};
