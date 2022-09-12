class Solution {
public:
    static bool csort(pair<int,int> a,pair<int,int> b){
        return a.second>b.second;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({speed[i],efficiency[i]});
        }
        int MOD=1e9+7;
        sort(v.begin(),v.end(),csort);
        multiset<int>ms;
        long long res=0,s=0;
        for(int i=0;i<n;i++){
            if(ms.size()==k){
                s-=*ms.begin();
                ms.erase(ms.begin());
                ms.insert(v[i].first);
                s+=v[i].first;
            }
            else
            {
                ms.insert(v[i].first);
                s+=v[i].first;
            }
            res=max(res,(s*v[i].second));
        }
        return res%MOD;
    }
};