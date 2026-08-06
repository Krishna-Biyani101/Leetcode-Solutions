class Solution {
public:
    int distance(vector<vector<pair<int,int>>>& adj, int u , int n , int dist)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.emplace(0,u);
        vector<bool> vis(n+1,false);
        while(!pq.empty()) 
        {
            auto [dis,v] = pq.top();
            pq.pop();
            if(!vis[v])
            {
                vis[v] = true;
                for(const auto& [neighbor, w] : adj[v]) 
                {
                    int d = dis + w;
                    if (d <= dist) 
                        pq.emplace(d,neighbor);
                }
            }
        }
        int cnt=0;
        for(bool x : vis)
            if(x)
                cnt++;
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        int m = n,ans = -1;
        for(int i = 0;i<n;i++) 
        {
            int cnt = distance(adj,i,n,distanceThreshold);
            if(cnt<=m) 
            {
                m = cnt;
                ans = i;
            }
        }
        return ans;
    }
};