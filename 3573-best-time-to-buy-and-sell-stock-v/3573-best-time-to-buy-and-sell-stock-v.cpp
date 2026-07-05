class Solution {
public:
    long long dp[1002][1002][3];
    int n;

    long long f(int i , int k , int s , vector<int>&p)
    {
        if(i==n)
        {
            if(k>=0&&s==0)
                return 0;
            return INT_MIN;
        }
        if(dp[i][k][s]!=NULL)
            return dp[i][k][s];
        if(k>0)
        {
            if(s==0)
                return dp[i][k][s] = max(p[i]+f(i+1,k,2,p),max(f(i+1,k,1,p)-p[i],f(i+1,k,s,p)));
            if(s==1)
                return dp[i][k][s] = max(f(i+1,k,s,p),p[i]+f(i+1,k-1,0,p));
            return dp[i][k][s] = max(f(i+1,k,s,p),f(i+1,k-1,0,p)-p[i]);
        }
        return dp[i][k][s] = f(i+1,k,s,p);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        return f(0,k,0,prices);
    }
};