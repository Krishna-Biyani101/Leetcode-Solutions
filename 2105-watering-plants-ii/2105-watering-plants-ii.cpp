class Solution {
public:
    int minimumRefill(vector<int>& plants, int A, int B) {
        int n = plants.size();
        int l = 0 , r = n-1;
        int s1=0,s2=0,ans=0;
        while(l<=r)
        {
            if(l==r)
            {
                if(s1+plants[l]<=A||s2+plants[l]<=B)
                    break;
                else
                {
                    ans++;
                    break;
                }
            }
            s1+= plants[l++];
            s2+= plants[r--];
            if(s1>A)
            {
                ans++;
                s1 = plants[l-1];
            }
            if(s2>B)
            {
                ans++;
                s2 = plants[r+1];
            }
        }
        return ans;
    }
};