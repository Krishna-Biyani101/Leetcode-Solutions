class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long>pref(n);
        long long m = pref[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            m = max((int)m,nums[i]);
            pref[i] = __gcd((int)m,nums[i]);
        }
        sort(pref.begin(),pref.end());
        long long sum = 0;
        for(int i=0;i<(n+1)/2;i++)
            sum+= (long long)__gcd(pref[i],pref[n-1-i]);
        if(n%2==1)
            sum-= pref[n/2];
        return sum;
    }
};