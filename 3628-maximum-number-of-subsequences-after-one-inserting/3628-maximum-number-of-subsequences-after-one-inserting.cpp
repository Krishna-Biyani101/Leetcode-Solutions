class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        vector<int>pr(n,0),sf(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='L')
                pr[i]=1;
            if(s[i]=='T')
                sf[i]=1;
        }
        for(int i=1;i<n;i++)
            pr[i]+=pr[i-1];
        for(int i=n-2;i>=0;i--)
            sf[i]+=sf[i+1];
        long long ans=0,ans1=0,ans2=0,ans3=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='C')
            {
                ans+= pr[i]*sf[i];
                ans1+= (pr[i]+1)*sf[i];
                ans2+= pr[i]*(sf[i]+1);
            }
            ans3 = max(ans3,1LL*pr[i]*sf[i]);
        }
        return max(ans+ans3,max(ans1,ans2));
    }
};