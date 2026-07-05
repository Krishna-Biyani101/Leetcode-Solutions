class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==1)
        {
            int b = INT_MAX,s=0;
            for(int x : prices)
            {
                    b = min(b,x);
                    s = max(s,x-b);
            }
            return s;
        }
        vector<int>b(k,INT_MAX),s(k,0);
            for(int x : prices)
            {
                for(int i=0;i<k-1;i++)
                {
                    b[i] = min(b[i],x);
                    s[i] = max(s[i],x-b[i]);
                    b[i+1] = min(b[i+1],x-s[i]);
                    s[i+1] = max(s[i+1],x-b[i+1]);
                }
            }
        return s[k-1];
    }
};