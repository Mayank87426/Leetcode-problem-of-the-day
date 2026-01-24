class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int i = 0, j = n - 1, maxSum = INT_MIN;
        while (i < j) {
            int sum = nums[i] + nums[j];
            maxSum = max(maxSum, sum);
            i++;
            j--;
        }
        return maxSum;
    }
};
