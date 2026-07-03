class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> m;
        for(int x : nums)
            m[x]++;
        int ans = 1;
        if (m.count(1))
        {
            ans = max(ans,m[1]%2?m[1]:m[1] - 1);
            m.erase(1);
        }
        for(auto it : m) 
        {
            long long x = it.first;
            int len = 0;
            while (m.count(x)&&m[x]>= 2) 
            {
                len += 2;
                if(x>1e9)
                    break;
                x = x*x;
            }
            if (m.count(x))
                len++;
            else
                len--;
            ans = max(ans,len);
        }
        return ans;
    }
};