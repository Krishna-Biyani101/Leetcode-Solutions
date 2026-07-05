class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)) ,w(n, vector<int>(n, 0));
        dp[n - 1][n - 1] = 0;
        w[n - 1][n - 1] = 1;
        for(int i = n-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(board[i][j] == 'X')
                    continue;
                if(i==n-1&&j==n-1)
                    continue;
                int ma = -1,cur=0;
                long long s = 0;
                if(i+1<n && dp[i+1][j]!=-1)
                {
                    if(dp[i+1][j]>ma)
                    {
                        ma = dp[i+1][j];
                        s = w[i+1][j];
                    }
                    else if(dp[i+1][j]==ma)
                        s = (s + w[i+1][j])%MOD;
                }
                if(j+1<n && dp[i][j+1]!=-1)
                {
                    if(dp[i][j+1]>ma)
                    {
                        ma = dp[i][j+1];
                        s = w[i][j+1];
                    }
                    else if(dp[i][j+1]==ma)
                        s = (s + w[i][j+1])%MOD;
                }
                if(i+1<n && j+1<n && dp[i+1][j+1]!=-1)
                {
                    if(dp[i+1][j+1]>ma)
                    {
                        ma = dp[i+1][j+1];
                        s = w[i+1][j+1];
                    }
                    else if(dp[i+1][j+1]==ma)
                        s = (s + w[i+1][j+1])%MOD;
                }
                if(ma==-1)
                    continue;
                if(board[i][j]>='1'&&board[i][j]<='9')
                    cur = board[i][j] - '0';
                dp[i][j] = ma + cur;
                w[i][j] = s%MOD;
            }
        }
        if(dp[0][0]==-1)
            return {0,0};
        return {dp[0][0],w[0][0]};
    }
};