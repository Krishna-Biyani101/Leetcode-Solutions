class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        bitset<101> b=0;
        int mi=101,ma=0;
        for(int x: nums)
        {
            b[x]=1;
            mi=min(x,mi);
            ma=max(x,ma);
        }
        vector<int> ans;
        for(int x=mi+1;x<ma;x++)
            if(!b[x]) 
                ans.push_back(x);
        return ans;
    }
};