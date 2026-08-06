class Solution {
public:
    int smallestNumber(int n, int t) {
        while(n%10!=0)
        {
            int p=1,m=n;
            while(m>0)
            {
                p*= (m%10);
                m/=10;
            }
            if(p%t==0)
                return n;
            n++;
        }
        return n;
    }
};