class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int o = 0;
        for(char c : s)
            if(c == '1')
                o++;
        s = "1" + s + "1";
        int n = s.size();
        int i = 0;
        int ans = o;
        while(i < n && s[i] == '1')
            i++;
        int c1 = 0;
        while(i < n && s[i] == '0')
        {
            c1++;
            i++;
        }
        while(i<n)
        {
            int c2 = 0;
            while(i < n && s[i] == '1')
            {
                c2++;
                i++;
            }
            if(c2==0)
                break;
            int c3 = 0;
            while(i < n && s[i] == '0')
            {
                c3++;
                i++;
            }
            if(c3==0)
                break;
            ans = max(ans,o + c1 + c3);
            c1 = c3;
        }
        return ans;
    }
};