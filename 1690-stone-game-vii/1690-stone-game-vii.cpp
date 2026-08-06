class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;	
    int f(int i, int j)
    {
        if(i>=j) 
            return 0;
        if(dp[i][j]!=-1) 
            return dp[i][j];
        return dp[i][j] = max(pref[j + 1] - pref[i + 1] - f(i+1,j),pref[j] - pref[i] - f(i,j-1));
    }
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        dp.assign(n,vector<int>(n,-1));
        pref.assign(n+1,0);
        for(int i = 0; i < n;i++) 
            pref[i + 1] = pref[i] + stones[i];
        return f(0,n-1);
    }
};