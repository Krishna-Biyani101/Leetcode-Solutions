class Solution {
public:
    void solve(string s, int c1, int c2, vector<string> &ans){
        if(c1==0&&c2==0)
        {
            ans.push_back(s);
            return;
        }
        if(c1==c2)
        {
            string s1 = s;
            s1.push_back('(');
            solve(s1,c1-1,c2,ans);
        }
        else if(c1 == 0)
        {
            string s1 = s;
            s1.push_back(')');
            solve(s1,c1,c2-1,ans);
        }
        else if(c2 == 0)
        {
            string s1 = s;
            s1.push_back('(');
            solve(s1,c1-1,c2,ans);
        }
        else{
            string s1 = s,s2 = s;
            s1.push_back('(');
            s2.push_back(')');
            solve(s1,c1-1,c2,ans);
            solve(s2,c1,c2-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        int c1 = n,c2=n;
        vector<string>ans;
        string s = "";
        solve(s,c1,c2,ans);
        return ans;
    }
};