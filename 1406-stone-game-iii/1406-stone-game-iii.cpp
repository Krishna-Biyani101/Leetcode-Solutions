class Solution {
public:
    vector<int>dp;
    int play(int i, vector<int>& sv, int n){
        if(dp[i]!=INT_MIN) 
            return dp[i];
        int result=sv[i]-play(i+1,sv, n);
        if (i+2<=n)
            result=max(result,sv[i]+sv[i+1]-play(i+2, sv,n));
        if (i+3<=n)
            result=max(result,sv[i]+sv[i+1]+sv[i+2]-play(i+3, sv,n));
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+1,INT_MIN);
        dp[n]=0;
        int ans = play(0,stoneValue,n);
        if (ans>0) 
            return "Alice";
        if (ans<0) 
            return "Bob";
        return "Tie";
    }
};