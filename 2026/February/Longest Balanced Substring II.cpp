class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {

        vector<vector<tuple<int,int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            int start = e[2], end = e[3];
            adj[u].push_back({v, start, end});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while (!pq.empty()) {
            auto [t, node] = pq.top();
            pq.pop();

            if (t > dist[node]) continue;

            for (auto &[v, start, end] : adj[node]) {

                if (t > end) continue;  

                long long arrive;

                if (t >= start)
                    arrive = t + 1;
                else
                    arrive = start + 1;

                if (arrive < dist[v]) {
                    dist[v] = arrive;
                    pq.push({arrive, v});
                }
            }
        }

        return dist[n-1] == LLONG_MAX ? -1 : dist[n-1];
    }
};
