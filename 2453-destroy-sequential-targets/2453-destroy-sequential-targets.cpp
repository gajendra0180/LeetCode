class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        vector<int>r;
         sort(nums.begin(),nums.end());
        map<int,int>m;
        for(auto i:nums){
            r.push_back(i%space);
            m[i%space]++;
        }
        int muxr=0,muxv=0;
        for(auto i:m){
            if(i.second>muxr)
            {
                muxr=i.second;
                muxv=i.first;
            }
        }
        int res=INT_MAX;
        for(auto i:nums){
            if(m[i%space]==muxr){
                  res=min(res,i);              
            }
        }
        return res;
    }
};