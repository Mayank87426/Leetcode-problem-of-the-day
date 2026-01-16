class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars,
                               vector<int>& vBars) {
        sort(begin(hBars), end(hBars));
        sort(begin(vBars), end(vBars));
        int maxLen = 1, maxWidth = 1;
        int len = hBars.size(), Vlen = vBars.size();
        int consecutiveHeight = 1, consecutiveWidth = 1;
        for (int i = 1; i < len; i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                consecutiveHeight++;
            } else {
                consecutiveHeight = 1;
            }
            maxLen = max(maxLen, consecutiveHeight);
        }
        for (int i = 1; i < Vlen; i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                consecutiveWidth++;
            } else {
               
                consecutiveWidth = 1;
            }
             maxWidth = max(maxWidth, consecutiveWidth);
        }
        int side = min(maxLen + 1, maxWidth + 1);
        return pow(side, 2);
    }
};
