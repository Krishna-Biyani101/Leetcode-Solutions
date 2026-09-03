class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int c=0;
        int x = *min_element(nums1.begin(),nums1.end());
        for(int i : nums1)
            c+= i&1;
        if(c==0||x&1)
            return 1;
        return 0;
    }
};