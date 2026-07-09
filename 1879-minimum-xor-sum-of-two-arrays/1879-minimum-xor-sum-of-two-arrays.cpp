class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n,vector<int>((1<<n),-1));
        auto f = [&](this auto f ,int i,int mask) -> int
        {
            if(i==n)
                return 0;
            if(dp[i][mask]!=-1) 
                return dp[i][mask];
            int ans=INT_MAX;
            for(int j=0;j<n;j++)
            {
                if(((1<<j)&mask)==0)
                    ans = min(ans,(nums1[i]^nums2[j]) + f(i+1,mask|(1<<j)));
            }
            return dp[i][mask] = ans;
        };
        return f(0,0);
    }
};