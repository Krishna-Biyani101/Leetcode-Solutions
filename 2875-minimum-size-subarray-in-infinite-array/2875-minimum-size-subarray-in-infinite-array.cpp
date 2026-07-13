class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long total = accumulate(nums.begin(), nums.end(), 0LL),sum = 0;
        int n = nums.size(), ans1 = n,ans2 = n*(target/total),l = 0;
        target %=total;
        for(int r = 0;r<2*n;r++) 
        {
            sum += nums[r%n];
            while(sum > target) 
                sum -= nums[l++%n];
            if(sum == target) 
                ans1 = min(ans1,r-l+1);
        }
        return (ans1!= n?ans1 + ans2:-1);
    }
};