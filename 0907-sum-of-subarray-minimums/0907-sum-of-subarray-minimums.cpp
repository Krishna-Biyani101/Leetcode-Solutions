
class Solution {
public:
    const int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n,-1LL),right(n, n);
        stack<long long> st;
        for(int i = 0;i<n;i++) 
        {
            while(!st.empty() && nums[st.top()] >= nums[i]) 
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for (int i = n-1;i>=0;i--) 
        {
            while(!st.empty() && nums[st.top()] > nums[i]) 
                st.pop();
            if(!st.empty()) 
                right[i] = st.top();
            st.push(i);
        }
        long long ans = 0;
        for(int i = 0;i<n;i++)
        {
            ans += ((i-left[i])*(right[i]-i)*nums[i])%MOD;
            ans %= MOD;
        }
        return ans;
    }
};