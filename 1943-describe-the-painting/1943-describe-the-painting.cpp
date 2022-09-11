class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        map<long long,long long> m;
        for(auto i:segments){
            m[i[0]]+=(long long)i[2];
            m[i[1]]-=(long long)i[2];
        }
        vector<long long>a,b;
        for(auto i:m){
            a.push_back(i.first);
            b.push_back(i.second);
        }
        long long res=b[0];
        vector<vector<long long>>r;
        for(int i=1;i<a.size();i++){
            if(res!=0)
            r.push_back({a[i-1],a[i],res});
            res+=(long long)b[i];
        }
        return r;
    }
};

// 1 14
// 4 2
// 7 -16