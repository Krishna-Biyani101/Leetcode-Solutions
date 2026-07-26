class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len = nums.size();
        vector<int>ans;
        for(int num : nums) 
        {
            int idx = abs(num);
            if(nums[idx-1] < 0) 
                ans.push_back(idx);
            nums[idx-1] = -nums[idx-1];
        }
        return ans;
    }
};