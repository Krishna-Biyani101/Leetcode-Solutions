class Solution {
public:
    int f(int i, int j,vector<int>& nums) 
    {
        int p2 = 0,p1 = 0;
        for(int k = i;k<=j;k++) 
        {
            int p = max(p1,p2 + nums[k]);
            p2 = p1;
            p1 = p;
        }
        return p1;
    }    

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) 
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        return max(f(0,n-2,nums),f(1,n-1,nums));        
    }

    
};