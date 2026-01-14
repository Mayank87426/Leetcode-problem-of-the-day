
class Solution {
public:
    vector<int> nextSmallerIndices(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                result[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
    vector<int> nearestSmallerToLeftIndices(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                result[i] = st.top();
            }
            st.push(i);
        }

        return result;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsr = nextSmallerIndices(heights);
        vector<int> nsl = nearestSmallerToLeftIndices(heights);
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            int height = heights[i];
            int width = nsr[i] - nsl[i] - 1;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size(), m = matrix[0].size();
        vector<int> heights(m, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }
            ans = max(ans, largestRectangleArea(heights));
        }

        return ans;
    }
};
