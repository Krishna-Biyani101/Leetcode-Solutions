class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n),suff(n);
        int ans = 0;
        pre[0] = nums[0];
            for(int j = 1;j<n;j++)
                pre[j] = gcd(pre[j-1],nums[j]);
            suff[n-1] = nums[n-1];
            for(int j = n-2;j>=0;j--)
                suff[j] = gcd(suff[j+1],nums[j]);
            for(int j = 0;j<n-1;j++)
                if(pre[j] == suff[j+1])
                    ans++;
        for(int i = 0;i<n;i++)
        {
            vector<int> arr;
            for(int j = 0;j<n;j++)
            {
                if(i==j)
                    continue;
                arr.push_back(nums[j]);
            }
            if(n<3) 
                continue;
            vector<int> pref(n-1),suf(n-1);
            pref[0] = arr[0];
            for(int j = 1;j<n-1;j++)
                pref[j] = gcd(pref[j-1],arr[j]);
            suf[n-2] = arr[n-2];
            for(int j = n-3;j>=0;j--)
                suf[j] = gcd(suf[j+1],arr[j]);
            int cnt = 0;
            for(int j = 0;j<n-2;j++)
                if(pref[j] == suf[j+1])
                    cnt++;
            ans = max(ans,cnt);
        }
        return ans;
    }
};