class Solution {
public:
    int cnt = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int m, int n) 
    {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == 1)
        {
            cnt++;
            dfs(grid,i-1,j,m,n);
        }
        if (i + 1 < m && grid[i + 1][j] == 1)
        {
            cnt++;
            dfs(grid,i+1,j,m,n);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
        {
            cnt++;
            dfs(grid,i,j-1,m,n);
        }
        if (j + 1 < n && grid[i][j + 1] == 1)
        {
            cnt++;
            dfs(grid,i,j+1,m,n);
        }
    }
     int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        for(int i = 0;i<m;i++) 
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j] == 1) 
                {
                    dfs(grid,i,j,m,n);
                    ans = max(ans,cnt+1);
                    cnt=0;
                }
            }
        }
        return ans;
    }
};