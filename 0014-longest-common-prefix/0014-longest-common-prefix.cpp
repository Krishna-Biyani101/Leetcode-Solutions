class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if(n==1)
            return strs[0];
        int len = min(strs[0].size(),strs[1].size());
        for(int i=ans.size();i<len;i++)
            {
                if(strs[0][i]!=strs[1][i])
                    break;
                ans+= strs[0][i];
            }
        for(int j=2;j<n;j++)
        {
            string temp = "";
            for(int i=0;i<strs[j].size();i++)
            {
                if(strs[j][i]!=ans[i])
                    break;
                temp+=strs[j][i];
            }
            ans = temp;
        }
        return ans;
    }
};