class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto& f : times) 
            adj[f[0]].push_back({f[1], f[2]});
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        queue<pair<int, int>> q;
        q.push({k,0});
        while (!q.empty()) 
        {
            int sz = q.size();
                while (sz--) {
                auto [u, cost] = q.front();
                q.pop();
                for (auto& [v, wt] : adj[u]) {
                    if (cost + wt < dist[v]) {
                        dist[v] = cost + wt;
                        q.push({v, dist[v]});
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
