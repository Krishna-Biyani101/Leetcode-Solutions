class Solution {
    using ll = long long;
public:
    int n;
    ll f(vector<int>& a , vector<int>&b , int i , int j , vector<vector<ll>>&dp)
    {
        if(i==4)
                return 0;
            if(j>=n)
                return INT_MIN;
            if(dp[i][j]!=-1)
                return dp[i][j];
            ll t = (ll)a[i]*b[j] + f(a,b,i+1,j+1,dp);
            ll nt = f(a,b,i,j+1,dp);
            return dp[i][j] = max(t,nt);
    }   
    long long maxScore(vector<int>& a, vector<int>& b) {
        n = b.size();
        if(n==4)
        {
            ll ans=0;
            for(int i=0;i<4;i++)
                ans+= (ll)a[i]*b[i];
            return ans;
        }
        vector<vector<ll>>dp(4,vector<ll>(n+2,-1));
        //auto f = [&](this auto f , int i , int j) -> ll
        //{
            
        //};
        return f(a,b,0,0,dp);
    }
};