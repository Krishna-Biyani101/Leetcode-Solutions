class Solution {
    long long MOD = 1e9+7;
public:
    long long modpow(long long a,long long b)
    {
        long long res = 1;
        while(b>0)
        {
            if(b&1)
                res = res*a % MOD;
            a = a*a %MOD;
            b >>= 1;
        }
        return res%MOD;
    }
    long long sumDecoded(vector<long long>& nums) {
        long long ans = 0;
        for(long long x : nums)
        {
            long long width = x%10;
            long long d = x/10;
            string s = to_string(d);
            string start = s.substr(0,width);
            string end = s.substr(width);
            long long a = stoll(start);
            long long b = stoll(end);
            long long p = modpow(a,b);
            ans = (ans+p)%MOD;
        }
        return ans;
    }
};