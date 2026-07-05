class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>b(2,INT_MAX),s(2,0);
            for(int x : prices)
            {
                for(int i=0;i<1;i++)
                {
                    b[i] = min(b[i],x);
                    s[i] = max(s[i],x-b[i]);
                    b[i+1] = min(b[i+1],x-s[i]);
                    s[i+1] = max(s[i+1],x-b[i+1]);
                }
            }
        return s[1];
    }
};