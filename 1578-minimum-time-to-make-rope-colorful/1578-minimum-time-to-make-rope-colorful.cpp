class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(),sum = 0;
        for (int i = 1;i<n;i++) 
        {
            int m = 0;
            while(i<n&& colors[i]==colors[i-1])
            {
                sum += neededTime[i-1];
                m = max(m,neededTime[i-1]);
                ++i;
            }
            sum += neededTime[i-1];
            m = max(m,neededTime[i-1]);
            sum -= m;
        }
        return sum;
    }
};