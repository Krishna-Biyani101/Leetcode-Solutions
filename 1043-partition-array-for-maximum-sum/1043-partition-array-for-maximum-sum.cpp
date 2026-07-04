class Solution {
public:
    int dp[501];

    int solve(vector<int>& arr, int k, int i) {
        if(i>=arr.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int m = 0;
        int ans = 0;
        for(int j = i;j<arr.size()&&j-i+1<=k;j++) 
        {
            m = max(m, arr[j]);
            ans = max(ans,((m*(j - i + 1)) + solve(arr,k,j + 1)));
        }
        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,k,0);
    }
};