class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        vector<vector<int>> adj(edges.size() + 1);
        vector<int>vis(100001,0);
        for(auto &e : edges) 
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        auto dfs = [&](this auto& dfs , int i , int p , int shift) -> int
        {
            if(shift>13) 
            return 0;
            if(vis[i] > shift) 
                return 0;
            int op1 = (coins[i]>>shift) - k;
            int op2 = coins[i]>>(shift + 1);
            vis[i]++;
            for(int j : adj[i])
                if(j!=p) 
                {
                    op1 += dfs(j,i,shift);
                    op2 += dfs(j,i,shift + 1);
                }
            return max(op1,op2);
        };
        return dfs(0,-1,0);
    }
};