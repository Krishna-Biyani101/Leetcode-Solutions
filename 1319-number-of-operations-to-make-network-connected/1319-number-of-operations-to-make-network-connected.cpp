class Solution {
public:
     void dfs(vector<vector<int>> &adj, vector<bool> &vis, int v)
    {
        vis[v] = true;
        for(int i : adj[v])
            if(!vis[i])
                dfs(adj, vis, i);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n,false);
        int cnt = 0;
        for(int i=0;i<n;i++)
            if(!vis[i])
            {
                dfs(adj,vis,i);
                cnt++;
            }
        return cnt - 1;
    }
};