class Solution {
public:
    void f(int ind, int t,int k, vector<int>& a,vector<vector<int>>& ans,vector<int>& comb) 
    {
        if(t == 0&&k==0) 
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
            f(i + 1,t - a[i],k-1,a,ans,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>a(9);
        iota(a.begin(),a.end(),1);
        vector<vector<int>>ans;
        vector<int>comb;
        f(0,n,k,a,ans,comb);
        return ans;
    }
};