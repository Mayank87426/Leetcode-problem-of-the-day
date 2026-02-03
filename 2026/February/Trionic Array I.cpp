class Solution {
public:
    bool check(vector<int>& nums, int p, int q) {
        int n = nums.size();
        bool f1 = true, f2 = true, f3 = true;
        for (int i = 0; i + 1 <= p; i++) {
            int curr = nums[i];
            int next = nums[i + 1];
            if (next <= curr) {
                f1 = false;
            }
        }
        for (int i = p; i + 1 <= q; i++) {
            int curr = nums[i];
            int next = nums[i + 1];
            if (next >= curr) {
                f2 = false;
            }
        }
        for (int i = q; i + 1 < n; i++) {
            int curr = nums[i];
            int next = nums[i + 1];
            if (next <= curr) {
                f3 = false;
            }
        }

        return f1 && f2 && f3;
    }
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j > i && (i > 0 && j < n - 1) && check(nums, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
};
