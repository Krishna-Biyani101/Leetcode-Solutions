class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0,c = 0,x = -1,in0 = -1;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                c = 0;
                in0 = i;
                x = -1;
            }
            else if(nums[i]>0)
            {   
                if(c&1)
                    ans = max(ans,i-x);
                else
                    ans = max(ans,i-in0);
            }
            else
            {
                c++;
                if(c&1)
                {
                    if(x!=-1)
                        ans = max(ans,i-x);
                    else
                        x = i;
                }
                else
                    ans = max(i-in0,ans);
            }
        }
        return ans;
    }
};