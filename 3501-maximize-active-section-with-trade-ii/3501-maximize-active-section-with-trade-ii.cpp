class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int ones = 0;
        for(char ch : s)
            if(ch=='1')
                ones++;
        vector<int> zs,ze;
        int i=0;
        while(i<n)
        {
            if(s[i] == '0') 
            {
                int j = i;
                while(j < n && s[j] == '0')
                    j++;
                zs.push_back(i); 
                ze.push_back(j - 1);
                i = j;
            } 
            else
                i++;
        }
        int blocks = zs.size();
        vector<int> v;
        for(int i = 0; i<blocks-1;i++)
            v.push_back((ze[i] - zs[i] + 1) + (ze[i + 1] - zs[i + 1] + 1));
        int nv = v.size();
        vector<vector<int>> sparse{v};
        for(int i = 1; i * 2 <= nv; i *= 2) 
        {
            auto& prev = sparse.back();
            vector<int> next;
            next.reserve(prev.size() - i);
            for(int j = 0; j<(int)prev.size()-i;j++)
                next.push_back(max(prev[j], prev[j + i]));
            sparse.push_back(move(next));
        }
        auto rmq = [&](int lo, int hi) 
        {           
            int t = bit_width(unsigned(hi - lo + 1)) - 1;
            return max(sparse[t][lo], sparse[t][hi - (1 << t) + 1]);
        };
        auto clip = [&](int j, int l, int r) 
        {       
            return v[j] - max(0, l - zs[j]) - max(0, ze[j + 1] - r);
        };
        auto gain = [&](int l, int r) 
        {
            if (blocks < 2) return 0;
            int ja = lower_bound(ze.begin(),ze.end(), l) - ze.begin();   
            int jb = upper_bound(zs.begin(),zs.end(), r) - zs.begin() - 2;
            if (ja > jb) 
                return 0;
            return max({clip(ja, l, r), clip(jb, l, r), jb - ja >= 2 ? rmq(ja + 1, jb - 1) : 0});
        };
        vector<int> ans;
        for(auto it : queries) 
            ans.push_back(ones + gain(it[0],it[1]));
        return ans;
    }
};