class Solution {
public:
    
    int minn(vector<vector<int>> &v,int r,int c,map<pair<int,int>,int> &m)
    {
        if(r==v.size())
            return 0;
        
        if(m.find({r,c})!=m.end())
            return m[{r,c}];
        
        return m[{r,c}] = min(v[r][c]+minn(v,r+1,c,m),v[r][c+1]+minn(v,r+1,c+1,m));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        map<pair<int,int>,int>m;
        return triangle[0][0]+minn(triangle,1,0,m);
        
    }
};