class Solution {
public:
    int reverseBits(int n) {
        if (!n)
            return 0;
        int result = 0;
        for (int i = 1; i <= 32; i++) {
            result <<= 1;
            int val =( n & 1);
            result = (result | val);
            n >>= 1;
        }
        return result;
    }
};
