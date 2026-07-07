class Solution {
public:
        int minCapability(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 1,r = 1e9;
        while(l<r) 
        {
            int mid = (l+r)/2;
            int c=0;
            for(int i = 0;i<n;i++)
            {
                if(nums[i]<=mid) 
                {
                    c++;
                    i++;
                }
            }
            if(c>=k)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};