class Solution {
public:
    int maxBottlesDrunk(int n, int c) {
        int ans=0;
        while(n>0)
        {
            if(n>=c)
            {
                n-=c;
                ans+=c;
                c++;
                n++;
            }
            else
            {
                ans+=n;
                break;
            }
        }
        return ans;
    }
};