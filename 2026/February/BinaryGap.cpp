class Solution {
public:
    int binaryGap(int n) {
        int maxDist = 0;
        for (int i = 0; i <= 31; i++) {
            for (int j = 0; j <= 31; j++) {
                if (i == j)
                    continue;
                if ((n >> i & 1) && n >> j & 1) {
                    maxDist = max(maxDist, abs(j - i));
                    i=j;
                }
            }
        }
        return maxDist;
    }
};
