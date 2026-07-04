class Solution {
public:
    int numTeams(vector<int>& rating) {
    int ans = 0,n=rating.size();
    for(int i = 1;i<n-1;i++) 
    {
        vector<int> l(2),h(2);
        for(int j = 0;j<n;j++) 
        {
            if(rating[i]<rating[j])
                l[j>i]++;
            if(rating[i]>rating[j])
                h[j>i]++;
        }
        ans += l[0]*h[1] + h[0]*l[1];
    }
    return ans;
}
};