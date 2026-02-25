class Solution {
public:
    int f(int x) { 
        return __builtin_popcount(x); 
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr), [&](int a, int b) {
            if (f(a) == f(b))
                return a < b;        
            return f(a) < f(b);    
        });
        return arr;
    }
};
