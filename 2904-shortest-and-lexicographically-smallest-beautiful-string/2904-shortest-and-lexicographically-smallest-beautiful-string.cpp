class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0,cnt = 0;
        string ans = "";
        for(int r = 0;r<n;r++) 
        {
            if(s[r] == '1')
                cnt++;
            while(cnt>k) 
            {
                if(s[l] == '1')
                    cnt--;
                l++;
            }
            if(cnt == k) 
            {
                while(l < r && s[l] == '0') 
                    l++;
                string cur = s.substr(l,r - l + 1);
                if(ans == "" || cur.size() < ans.size() ||(cur.size() == ans.size() && cur < ans)) 
                    ans = cur;
            }
        }
        return ans;
    }
};