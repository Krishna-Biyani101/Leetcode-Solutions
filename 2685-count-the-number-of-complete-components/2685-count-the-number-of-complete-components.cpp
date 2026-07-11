class Solution {
public:
    vector<int> parent,rank,ec;
    int find(int x) 
    {
        if(parent[x]==x) 
            return x; 
        return parent[x] = find(parent[x]);
    }
    void un(int x,int y) 
    {
        int rx = find(x),ry = find(y); 
        int rankx = parent[rx], ranky = parent[ry]; 
        if(rx==ry) 
        {
            ec[rx]++; 
            return; 
        }
        if(rankx>ranky) 
        {
            parent[ry] = rx; 
            ec[rx] += ec[ry] + 1; 
        } 
        else if(ranky>rankx) 
        {
            parent[rx] = ry; 
            ec[ry] += ec[rx] + 1; 
        } 
        else 
        {
            parent[rx] = ry; 
            ec[ry] += ec[rx] + 1; 
            rank[ry] += 1; 
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.reserve(n);
        rank.reserve(n);
        ec.reserve(n);
        for(int i = 0;i<n;i++) 
        {
            parent[i] = i; 
            rank[i] = 1; 
            ec[i] = 0; 
        }
        for(auto e : edges) 
            un(e[0],e[1]); 
        vector<int>nc(n);
        for(int i = 0;i<n;i++)
            nc[find(i)]++; 
        int cnt = 0; 
        for(int i = 0;i<n;i++) 
            if(nc[i]>0) 
                if(2*ec[i] == (nc[i]*(nc[i] - 1))) 
                    cnt++; 
        return cnt; 
    }
};