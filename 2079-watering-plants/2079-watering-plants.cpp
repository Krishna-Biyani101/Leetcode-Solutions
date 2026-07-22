class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        long long int ans=0,sum=0;
        int n = plants.size();
        for(int i=0;i<n;i++)
        {
            sum+=plants[i];
            if(sum>capacity)
            {
                ans+= 2LL*(i) + 1;
                sum=plants[i];
            }
            else
            {
                ans++;
            }
        }
        return ans;
    }
};