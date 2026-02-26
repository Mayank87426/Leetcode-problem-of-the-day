class Solution {
public:
    string f(string s) {
        int carry = 1;
        string str = "";
        int i = s.length() - 1;

        while (i >= 0) {
            int v = (s[i] - '0') + carry;

            str.push_back((v % 2) + '0'); 
            carry = v / 2;              

            i--;
        }

        if (carry)
            str.push_back('1');

        reverse(str.begin(), str.end());
        return str;
    }
    int numSteps(string s) {
        int steps = 0;
        while (s != "1") {
            if (!s.empty() && s.back() == '0') {
                s.pop_back();
            } else
                s = f(s);
            steps++;
        }
        return steps;
    }
};
