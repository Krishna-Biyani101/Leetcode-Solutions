class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<long long> pref(n+1,0),num(n+1,0),ex(n+1,1);
        vector<int> cnt(n+1,0),ans(m);
        for(int i = 1;i<=n;i++)
            ex[i] = (ex[i-1]*10)%MOD;
        for(int i = 0;i<n;i++)
        {
            int d = s[i] - '0';
            pref[i+1] = pref[i] + d;
            cnt[i+1] = cnt[i] + (d!= 0);
            if(d == 0)
                num[i+1] = num[i];
            else
                num[i+1] = (num[i]*10 + d)%MOD;
        }
        for(int i = 0;i<m;i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int len = cnt[r+1] - cnt[l];
            long long start = num[l];
            long long end = num[r+1];
            long long x = (end - (start*ex[len])%MOD + MOD)%MOD;
            long long sum = pref[r+1] - pref[l];
            ans[i] = (x*sum)%MOD;
        }
        return ans;
    }
};