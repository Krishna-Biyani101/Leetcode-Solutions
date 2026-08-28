class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26,0);
        for(char ch : s) 
            cnt[ch - 'a']++;
        for(int i = n-1;i>=0;i--) 
        {
            vector<int> remain = cnt;
            bool flag = true;
            for(int j = 0;j<i;j++) 
            {
                int x = target[j] - 'a';
                if(remain[x] == 0) 
                {
                    flag = false;
                    break;
                }
                remain[x]--;
            }
            if(!flag)
                continue;
            int chr = target[i] - 'a';
            for(int c = chr + 1;c<26;c++) 
            {
                if(remain[c] == 0)
                    continue;
                string ans = target.substr(0, i);
                ans += char('a' + c);
                remain[c]--;
                for(int x = 0;x<26;x++) 
                    ans.append(remain[x],char('a' + x));
                return ans;
            }
        }
        return "";
    }
};