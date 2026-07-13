class Solution {
public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        auto f = [&](this auto f ,int i , int l) -> int
        {
            if(i+1>=n)
                return max(nums[l],((i<n)?nums[i]:0));
            if(dp[i][l]!=-1)
                return dp[i][l];
            int res = max(nums[i],nums[i+1]) + f(i+2,l);
            res = min(res,max(nums[i],nums[l]) + f(i+2,i+1));
            res = min(res,max(nums[i+1],nums[l]) + f(i+2,i));
            return dp[i][l] = res;
        };
        return f(1,0);
    }
};