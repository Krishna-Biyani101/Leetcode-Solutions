class Solution {
public:
    vector<vector<int>> dp;
    vector<int> suf;
    int n;
    int f(int i, int m, vector<int>& piles) {
        if (i>=n)
            return 0;
        if (2*m >=n-i)
            return suf[i];
        if (dp[i][m] != -1)
            return dp[i][m];
        int ans = 0;
        for(int x = 1;x<= min(2*m,n-i);x++) 
            ans = max(ans,suf[i] - f(i+x,max(m,x),piles));
        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suf.resize(n);
        suf[n - 1] = piles[n - 1];
        for(int i = n-2;i>=0;i--)
            suf[i] = suf[i + 1] + piles[i];
        dp.assign(n,vector<int>(n+1,-1));
        return f(0,1,piles);
    }
};