class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> edges(n);
        vector<int> in(n,0);
        bitset<100002> sus;
        for(auto it : invocations) 
        {
            edges[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        queue<int>q;
        q.push(k);
        sus.set(k);
        while(!q.empty()) 
        {
            int u = q.front();
            q.pop();
            for(int v : edges[u]) 
            {
                in[v]--;
                if(!sus.test(v)) 
                {
                    q.push(v);
                    sus.set(v);
                }
            }
        }
        bool flag = true;
        vector<int> ans;
        for(int i = 0;i<n;i++) 
        {
            if(sus.test(i) && in[i] > 0) 
            {
                flag = false;
                break;
            } 
            else if(!sus.test(i)) 
                ans.push_back(i);
        }
        if(!flag) 
        {
            vector<int> a(n);
            iota(a.begin(),a.end(),0);
            return a;
        }
        return ans;
    }
};