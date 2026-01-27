class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
       
        vector<vector<pair<int, int>>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], 2 * e[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>  pq;
          
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, u] = pq.top();
            pq.pop();

            if (cost > dist[u])
                continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[v] > cost + w) {
                    dist[v] = cost + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
