class Solution{
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B)
    {
        int len = A.size();
        vector<vector<long long>> C(len, vector<long long>(len, 0));
        for(int i = 0;i<len;i++) 
        {
            for(int k = 0;k<len;k++) 
            {
                if(!A[i][k]) 
                    continue;
                for(int j = 0;j<len;j++) 
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }

        return C;
    }

    long long zigZagArrays(int n, int l, int r) {
        if (n == 1) 
            return r - l + 1;
        int k = r - l + 1;
        int len = 2*k;
        vector<vector<long long>> M(len,vector<long long>(len,0));
        for(int i = 0;i<k;i++)
        {
            for(int j = 0;j<i;j++)
                M[i][k + j] = 1;
            for(int j = i + 1;j<k;j++) 
                M[k + i][j] = 1;
        }
        vector<vector<long long>> res(len, vector<long long>(len,0));
        for(int i = 0;i<len;i++)
            res[i][i] = 1;
        long long p = n - 1;
        while(p>0) 
        {
            if (p&1)
                res = multiply(res, M);
            M = multiply(M, M);
            p /= 2;
        }
        long long ans = 0;
        for(int i = 0;i<len;i++)
            for(int j = 0;j<len;j++)
                ans = (ans + res[i][j])%MOD;
        return ans;
    }
};