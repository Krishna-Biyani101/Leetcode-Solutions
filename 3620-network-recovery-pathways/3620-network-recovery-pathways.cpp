class Solution {
public:
    int n;
    bool find(int limit, unordered_map<int, vector<pair<int,int>>>& adj,
              vector<bool>& online, vector<int>& t, long long k)
    {
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        for(int node : t)
        {
            if(dist[node] == LLONG_MAX) 
                continue;
            for(auto &nxt : adj[node])
            {
                int nxtNode = nxt.first;
                int cst = nxt.second;
                if(cst < limit) 
                    continue;
                if(nxtNode != n-1 && !online[nxtNode]) 
                    continue;
                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst);
            }
        }
        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<int> id(n,0),t;
        int l = INT_MAX;
        int r = 0;
        for(auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int cst = e[2];
            adj[u].push_back({v, cst});
            id[v]++;
            l = min(l, cst);
            r = max(r, cst);
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(id[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            t.push_back(node);
            for(auto &ngbr : adj[node])
            {
                int nxtNode = ngbr.first;
                id[nxtNode]--;
                if(id[nxtNode] == 0){
                    q.push(nxtNode);
                }
            }
        }
        int ans = -1;
        while(l <= r)
        {
            int mid = l + (r - l)/2;
            if(find(mid, adj, online, t, k))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};