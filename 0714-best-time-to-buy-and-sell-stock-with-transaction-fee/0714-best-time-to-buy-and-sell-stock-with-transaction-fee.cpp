class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int b = INT_MIN,s = 0;
        for (int x : prices)
        {
            b = max(b,s-x);
            s = max(s,b+x - fee);
        }
        return s;
    }
};