class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>v;
        for(auto i:nums){
            if(m.find(i)==m.end())
                v.push_back(__builtin_popcount(i));
            m[i]++;
        }
        sort(v.begin(),v.end());
        // [1,1,2]
        long long res=0;
        for(int i=0;i<v.size();i++){
            int req=k-v[i];
            auto it=v.end()-lower_bound(v.begin(),v.end(),req);
            res+=it*1LL;
        }
        return res;
    }  
};

    