class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> seg(n,0);
        int c = 0;
        for(int i = 1;i<n;i++)
        {
            if(nums[i]-nums[i-1]>maxDiff)
                c++;
            seg[i] = c;
        }
        vector<bool>ans;
        for(auto it : queries)
            ans.push_back(seg[it[0]] == seg[it[1]]);
        return ans;
    }
};