class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int a = 0, b = 0,n = aliceValues.size();
        vector<int> v(n);
        iota(v.begin(),v.end(),0);
        sort(v.begin(),v.end(),[&](int i, int j) {
            return aliceValues[i] + bobValues[i] > aliceValues[j] + bobValues[j];
        });
        for(int i = 0;i<n;i++) 
        {
            if(i&1)
                b+= bobValues[v[i]];
            else
                a+= aliceValues[v[i]];
        }
        if(a>b)
            return 1;
        if(a==b)
            return 0;
        return -1;
    }
};