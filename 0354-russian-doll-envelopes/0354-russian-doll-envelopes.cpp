class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](auto& a,auto& b)
        {
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=envelopes.size();
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            int h=envelopes[i][1];
            if(a.empty() || a.back()<h)
                a.push_back(h);
            else
            {
                auto it = lower_bound(a.begin(),a.end(),h);
                *it=h;
            }
        }
        return a.size();
    }
};