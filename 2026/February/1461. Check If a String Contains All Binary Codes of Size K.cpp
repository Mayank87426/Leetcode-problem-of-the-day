class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int total=1<<k;
        unordered_set<string>st;
        int n=s.length();
        for(int i=k;i<=n;i++){
            string str=s.substr(i-k,k);
            if(!st.count(str)){
                st.insert(str);
                total--;
            }
            if(!total)return true;
        }
        return false;
    }
};
