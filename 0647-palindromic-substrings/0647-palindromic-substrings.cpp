class Solution {
public:
    int check(string st,int i,int j) 
    {
        int c = 0;
        int n = st.length();
        while(i>=0&&j<n) 
        {
            if(st[i]==st[j]) 
            {
                c++;
                i--;
                j++;
            }
            else
                break;
        }
        return c;
    }

    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++) 
        {
            ans+=check(s,i,i);
            ans+=check(s,i,i+1);
        }
        return ans;
    }
};