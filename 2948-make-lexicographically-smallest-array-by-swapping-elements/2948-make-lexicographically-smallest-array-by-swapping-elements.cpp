class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        vector<vector<int>> g;
        unordered_map<int,int> mp;
        int id = -1;
        for(int i = 0;i<v.size();i++) 
        {
            if(i == 0 || v[i] - v[i - 1] > limit) 
            {
                g.push_back({});
                id++;
            }
            g[id].push_back(v[i]);
            mp[v[i]] = id;
        }
        vector<int> idx(g.size(),0);
        for(int i = 0;i<nums.size();i++) 
        {
            int cur = mp[nums[i]];
            nums[i] = g[cur][idx[cur]];
            idx[cur]++;
        }
        return nums;
    }
};