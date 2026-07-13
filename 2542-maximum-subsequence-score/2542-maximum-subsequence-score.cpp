class Solution {
    using ll = long long;
    public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
       vector<pair<int,int>>a;
        int n = nums2.size();
        for(int i = 0;i<n;i++)
            a.push_back({nums2[i],nums1[i]});
        sort(a.rbegin(),a.rend());
        ll sum  = 0;
        priority_queue<int> pq;
        for(int i = 0;i<k;i++)
        {
            sum += a[i].second;
            pq.push(-a[i].second);
        }
        ll ans = sum*a[k-1].first;
        for(int i = k;i<n;i++)
        {
            sum += pq.top();
            pq.pop();
            sum += a[i].second;
            pq.push(-a[i].second);
            ans = max(ans,sum*a[i].first);
        }
        return ans;
    }
};