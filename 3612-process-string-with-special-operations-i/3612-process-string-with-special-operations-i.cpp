class Solution {
public:
    string processStr(string s) {
        string res;
        for(char ch : s)
        {
           if(ch == '*') 
            {
                if(res.length() != 0)
                    res.pop_back();
            } 
            else if(ch == '#')
                res += res;
            else if(ch == '%') 
                reverse(res.begin(),res.end());
            else if(ch >='a'&&ch<= 'z')
                res.push_back(ch);
        }
        return res;
    }
};