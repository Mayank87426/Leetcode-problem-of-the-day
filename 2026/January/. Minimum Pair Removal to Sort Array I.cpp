class Solution {
public:
    bool isNonDecreasing(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int steps = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

           
            for (int i = 1; i < nums.size(); i++) {
                int s = nums[i] + nums[i - 1];
                if (s < minSum) {
                    minSum = s;
                    idx = i - 1;
                }
            }

           
            nums.erase(nums.begin() + idx);
            nums.erase(nums.begin() + idx);
            nums.insert(nums.begin() + idx, minSum);

            steps++;
        }

        return steps;
    }
};
