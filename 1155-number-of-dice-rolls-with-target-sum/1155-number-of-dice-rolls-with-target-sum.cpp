class Solution {
public:
    const int MOD = 1e9 + 7;
    int f(vector<vector<int>>& dp, int n, int k, int t) 
    {
        if(t == 0&&n == 0) 
            return 1;
        if(n == 0||t <= 0) 
            return 0;
        if(dp[n][t]!=-1) 
            return dp[n][t]%MOD;
        int ways = 0;
        for(int i = 1;i<=k;i++) 
            ways = (ways + f(dp,n-1,k,t-i))%MOD;
        return dp[n][t] = ways%MOD; 
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1,vector<int>(target + 1,-1));
        return f(dp,n,k,target);
    }
};


