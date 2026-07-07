class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long ans=0,sum=0;
        for(char ch : s)
        {
            if(ch!='0')
                ans = ans*10 + (ch-'0');
            sum+= ch-'0';
        }
        return ans*sum;
    }
};