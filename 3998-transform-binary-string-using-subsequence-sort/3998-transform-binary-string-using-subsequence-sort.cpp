class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n0 = 0,n1 = 0;
        int n = s.size();
        for(char ch : s)
        {
            if(ch=='0')
                n0++;
            else
                n1++;
        }
        vector<bool> ans;
        for(auto it : strs)
        {
            string t = "";
            string curr = "";
            int t0 = 0,t1 = 0;
            for(int i = 0;i<n;i++)
            {
                if(it[i]!=s[i])
                {
                    t.push_back(s[i]);
                    curr.push_back(it[i]);
                }
                if(it[i] == '0')
                    t0++;
                else if(it[i] == '1')
                    t1++;
            }
            if(t1 > n1 || t0 > n0)
            {
                ans.push_back(false);
                continue;
            }
            int d1 = n1 - t1;
            int d0 = n0 - t0;
            int i = 0;
            while(i < curr.size())
            {
                if(curr[i] == '?')
                {
                    if(d0 > 0)
                    {
                        curr[i] = '0';
                        d0--;
                    }
                    else
                        curr[i] = '1';
                }
                i++;
            }
            bool flag = true;
            int cnt1 = 0,cnt2 = 0;
            for(int i = 0;i < curr.size(); i++)
            {
                if(curr[i] == '0')
                    cnt2++;
                if(t[i] == '0')
                    cnt1++;
                if(cnt1 > cnt2)
                {
                    flag = false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};