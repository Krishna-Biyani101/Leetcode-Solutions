class Solution {
public:
    vector<int>dp;
    bool f(int i) 
    {
        if(i == 0)
            return dp[i] = false;
        if(dp[i] != -1) 
            return dp[i];
        for(int j = 1;j*j<=i;j++)
            if(!f(i - j*j)) 
                return dp[i] = true;
        return dp[i] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n+1,-1);
        return f(n);
    }
};