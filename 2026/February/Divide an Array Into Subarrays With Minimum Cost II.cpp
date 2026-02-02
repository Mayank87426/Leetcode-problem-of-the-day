class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> p;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ll sum = 0, result = LLONG_MAX;
        set<p> kMinElement, remaining;
        int i = 1;
        while (i - dist < 1) {
            sum += nums[i];
            kMinElement.insert({nums[i], i});
            if (kMinElement.size() > k - 1) {
                p toRemove = *kMinElement.rbegin();
                kMinElement.erase(toRemove);
                sum -= toRemove.first;
                remaining.insert(toRemove);
            }
            i++;
        }
        int n = nums.size();
        while (i < n) {
            kMinElement.insert({nums[i], i});
            sum += nums[i];
            if (kMinElement.size() > k - 1) {
                p toRemoved = *kMinElement.rbegin();
                kMinElement.erase(toRemoved);
                remaining.insert(toRemoved);
                sum -= toRemoved.first;
            }

            result = min(result, sum);
            p removed = {nums[i - dist], i - dist};
            if (kMinElement.count(removed)) {
                sum -= removed.first;
                kMinElement.erase(removed);
                if (!remaining.empty()) {
                    p temp = *remaining.begin();
                    sum += temp.first;
                    kMinElement.insert(temp);
                    remaining.erase(temp);
                }
            } else {
                remaining.erase(removed);
            }
            i++;
        }
        return result + nums[0];
    }
};
