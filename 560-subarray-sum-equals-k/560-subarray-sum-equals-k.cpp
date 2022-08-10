class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>pre;
        int s=0;
        for(auto i:nums){
            s+=i;
            pre.push_back(s);
        }
        int res=0;
        map<int,int> m;
        m[0]=1;
        for(auto i:pre){
            int req=i-k;
            if(m.find(req)!=m.end())
                res+=m[req];
            m[i]++;
        }
        return res;
    }
};
// [1,0,0]
