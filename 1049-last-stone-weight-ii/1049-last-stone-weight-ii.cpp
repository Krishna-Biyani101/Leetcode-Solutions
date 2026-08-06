class Solution {
public:
    vector<vector<int>>dp;
    int f(int i, vector<int>& stones, int total, int s) 
    {
        if(i >= stones.size())
            return 0;
        if(dp[i][s] != -1)
            return dp[i][s];
        int skip = f(i + 1,stones,total,s);
        int take = 0;
        if(2*(s + stones[i]) <= total)
            take = stones[i] + f(i + 1,stones,total,s + stones[i]);
        return dp[i][s] = max(skip, take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int s = 0,total = 0;
        int n = stones.size();
        for(int x : stones)
            total += x;
        dp.assign(n+1,vector<int>(total,-1));
        int half = f(0,stones,total,s);
        return total - (2*half);
    }
};