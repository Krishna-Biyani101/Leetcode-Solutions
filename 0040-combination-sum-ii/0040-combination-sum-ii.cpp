class Solution {
public:
    void f(int ind, int t, vector<int>& a,vector<vector<int>>& ans,vector<int>& comb) 
    {
        if(t == 0) 
        {
            ans.push_back(comb);
            return;
        }
        for(int i = ind;i<a.size();i++) 
        {
            if(i>ind&&a[i]==a[i-1]) 
                continue;
            if(a[i]>t) 
                break;
            comb.push_back(a[i]);
            f(i + 1,t - a[i],a,ans,comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>comb;
        f(0,target,candidates,ans,comb);
        return ans;
    }
};