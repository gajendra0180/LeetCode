class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        long long res=0;
        map<double,long long> m;
        for(int i=0;i<r.size();i++)
            m[r[i][0]/double(r[i][1])]++;
        
        for(auto i:m)
            res+=(i.second-1)*(i.second)/2;
        return res;
    }
};