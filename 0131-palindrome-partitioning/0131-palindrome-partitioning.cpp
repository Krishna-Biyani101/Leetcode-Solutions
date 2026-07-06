class Solution {
public:
    bool isPal(int i,int j,string& s) 
    {
            while(i<j)
                if(s[i++]!=s[j--])
                    return false;
            return true;
    }

    void f(string& s,int i,vector<string>& st,vector<vector<string>>& ans) 
    {
        if(i == s.size()) 
        {
            ans.push_back(st);
            return;
        }
        for(int j = i+1;j<= s.size();j++) 
        {
            if (isPal(i,j-1,s)) 
            {
                st.push_back(s.substr(i,j - i));
                f(s,j,st,ans);
                st.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>st;
        f(s,0,st,ans);
        return ans;
    }    
};