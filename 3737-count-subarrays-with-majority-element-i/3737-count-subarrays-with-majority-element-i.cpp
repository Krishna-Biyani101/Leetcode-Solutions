class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long cnt = 0;
        for (int i = 0;i<n;i++) 
        {
            if(nums[i] == target) 
                nums[i] = 1;
            else
                nums[i] = -1;
        }
        vector<int> pref(n);
        pref[0] = nums[0];
        for (int i = 1;i<n;i++)
            pref[i] = pref[i-1] + nums[i];
        vector<int> freq(2*n + 1,0);
        freq[n] = 1;
        long long c = 0;
        int s = 0;
        for(int i = 0;i<n;i++)
        {
            if(pref[i]>s) 
                c+= freq[s+n];
            else
                c-= freq[pref[i] + n];
            cnt+= c;
            freq[pref[i] + n]++;
            s = pref[i];
        }
        return cnt;
    }
};