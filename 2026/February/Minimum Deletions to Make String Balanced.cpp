class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int count = 0;
        for (auto x : s) {
            if (!st.empty() && st.top() == 'b' && x == 'a') {
                st.pop();
                count++;

            } else
                st.push(x);
        }
        return count;
    }
};
