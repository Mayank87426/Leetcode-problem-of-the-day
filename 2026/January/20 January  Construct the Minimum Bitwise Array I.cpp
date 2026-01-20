class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int val = 1; val <= 1000; val++) {
                if ( (val | (val + 1)) == nums[i] ) {
                    ans[i] = val;
                    found = true;
                    break;
                }
            }
            if (!found)
                ans[i] = -1;
        }
        return ans;
    }
};
