class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+2][2];
        for(int i=n+1;i>=0;i--)
        {
            for(int j=0;j<2;j++)
            {
                if(i>=n)
                    dp[i][j] = 0;
                else
                {
                    if(j&1)
                        dp[i][j] = max(dp[i+1][j],dp[i+1][0]-prices[i]);
                    else
                        dp[i][j] = max(dp[i+1][j],dp[i+2][1]+prices[i]);
                }
            }
        }
        return dp[0][1];
    }
};