class Solution {
public:
    //int dp[10002];
    int f(vector<int>& coins,int rem,vector<int>&dp) 
    {
        if(rem<0) 
            return -1;
        if(rem == 0) 
            return 0;
        if(dp[rem]!=-2) 
            return dp[rem]; 
        int m = INT_MAX;
        for(int x : coins) 
        {
            int ans = f(coins,rem - x,dp);
            if(ans>=0&&ans<m)
                m = 1 + ans;
        }
        return dp[rem] = ((m==INT_MAX)?-1:m);
    }

    int coinChange(vector<int>& coins, int amount) {
        //memset(dp,-2,sizeof(dp));
        vector<int>dp(10002,-2);
        return f(coins,amount,dp);
    }
    
};