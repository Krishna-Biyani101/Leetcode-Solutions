class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        vector<int> p(m+1,0),dp(m+1);
        for(int x:nums)
            p[x]+=x;
        dp[0]=p[0];
        dp[1]=max(p[0],p[1]);
        for(int i=2;i<=m;i++)
            dp[i]=max(dp[i-1],p[i]+dp[i-2]);
        return dp[m];
    }
};