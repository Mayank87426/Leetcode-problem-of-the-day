class Solution {
public:
    int minOperations(string s, int k) {
        queue<int> q;
        int n = s.length();
        int zeros = 0;
        for (auto x : s) {
            if (!(x - '0'))
                zeros++;
        }
        cout << zeros;
        vector<int> operations(n + 1, -1);
        operations[zeros] = 0;
        if (!zeros)
            return 0;
        q.push(zeros);
        set<int> even, odd;
        while (n >= 0) {
            if (n % 2)
                odd.insert(n);
            else
                even.insert(n);
            n--;
        }
        n = s.length();
        zeros % 2 ? odd.erase(zeros) : even.erase(zeros);
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            int min_new_z = z + k - 2 * min(k, z);
            int max_new_z = z + k - 2 * max(0, k - n + z);
            if (min_new_z % 2) {
                auto it = odd.lower_bound(min_new_z);
                while (it != odd.end() && *it <= max_new_z) {
                    int newz = *it;
                    if (operations[newz] == -1) {
                        operations[newz] = operations[z] + 1;
                        if (newz == 0)
                            return operations[newz];
                        q.push(newz);
                    }
                    it = odd.erase(it);
                }
            } else {
                auto it = even.lower_bound(min_new_z);
                while (it != even.end() && *it <= max_new_z) {
                    int newz = *it;
                    if (operations[newz] == -1) {
                        operations[newz] = operations[z] + 1;
                        if (newz == 0)
                            return operations[newz];
                        q.push(newz);
                    }

                    it = even.erase(it);
                }
            }
        }
        return -1;
    }
};
