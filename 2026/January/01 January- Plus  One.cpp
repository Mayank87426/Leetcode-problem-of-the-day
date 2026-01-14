class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), count = 0;
        for (auto x : digits) {
            if (x == 9)
                count++;
        }
        vector<int> ans;
        if (count == n) {
            ans.push_back(1);
           
            for (int i = 0; i < n; i++)
                ans.push_back(0);
         return ans;
        }
         else if (digits[n - 1] == 9) {
            digits[n - 1] = 0;
            int j = n - 2;
            int carry = 1;

            while (j>0&&digits[j] == 9) {
                int val=(digits[j] + carry);
                digits[j] = (digits[j] + carry) % 10;
                 carry=val/10;
                j--;
            }
            digits[j]++;
        } else {
            digits[n - 1]++;
        }
        return digits;
    }
}; 
