class Solution {
public:
    vector<vector<int>> dp;
    vector<int> pref;	
    int f(int i, int j, vector<int>& a)
    {
        if(i==j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=0;
        for(int k=i+1;k<=j;k++)
        {
			int l=pref[k]-pref[i];
            int r=pref[j+1]-pref[k];
			if(l<r)
                dp[i][j]=max(dp[i][j],l+f(i,k-1,a));
            else if(l>r)
                dp[i][j]=max(dp[i][j],r+f(k,j,a));
            else	
                dp[i][j]=max(dp[i][j],l+max(f(k,j,a),f(i,k-1,a)));
        }
        return dp[i][j];
    }
    int stoneGameV(vector<int>& stoneValue)
    {
        int n = stoneValue.size();
        dp.resize(n,vector<int>(n,-1));
        pref.resize(n+1,0);
        for(int i=0;i<n;i++)
            pref[i+1]=pref[i]+stoneValue[i];
        return f(0,n-1,stoneValue);
    }
};