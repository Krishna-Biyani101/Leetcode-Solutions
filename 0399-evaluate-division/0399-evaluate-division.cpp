class Solution {
public:
    bool dfs(string curr, string target,unordered_map<string, vector<pair<string, double>>> &adj,unordered_set<string> &vis,double &ans,double product) 
    {
        if(curr == target) 
        {
            ans = product;
            return true;
        }
        vis.insert(curr);
        for(auto &it : adj[curr]) 
        {
            string next = it.first;
            double wt = it.second;
            if (!vis.count(next)) 
            {
                if (dfs(next, target, adj, vis, ans, product * wt))
                    return true;
            }
        }
        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& v, vector<vector<string>>& q) {
        int n = eq.size();
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0;i<n;i++) 
        {
            adj[eq[i][0]].push_back({eq[i][1], v[i]});
            adj[eq[i][1]].push_back({eq[i][0], 1.0 / v[i]});
        }
        vector<double> res;
        for (int i = 0;i<q.size();i++) 
        {
            string st = q[i][0];
            string ed = q[i][1];
            if (!adj.count(st) || !adj.count(ed)) 
            {
                res.push_back(-1.0);
                continue;
            }
            if (st == ed) 
            {
                res.push_back(1.0);
                continue;
            }
            double ans = -1.0;
            unordered_set<string> vis;
            dfs(st, ed, adj, vis, ans, 1.0);
            res.push_back(ans);
        }
        return res;
    }
};