class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (int k = 1; k <= 3; ++k) {
            for (int i = 0; i + k < A.size(); ++i) {
                if (A[i] == A[i + k])
                    return A[i];
            }
        }
        return -1; 
    }
};
