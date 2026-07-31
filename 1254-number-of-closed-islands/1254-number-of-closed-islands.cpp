class Solution {
public:
    vector<int>dx={-1,1,0,0};
    vector<int>dy={0,0,1,-1};
    vector<vector<bool>>vis = vector<vector<bool>>(101,vector<bool>(101,false));
    bool dfs(int i,int j,vector<vector<int>>& grid)
    {
        bool cur=true;
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(min(nx,ny)<0 || nx>=grid.size() || ny>=grid[0].size()) 
                cur=false;
            else if(grid[nx][ny]==0 && vis[nx][ny]==false) 
                cur&=dfs(nx,ny,grid);
        }
        return cur;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]==0 && !vis[i][j]) 
                    ans+=(dfs(i,j,grid)?1:0);
            
        return ans;
    }
};