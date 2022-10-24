class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        map<int,int>m;
        int dup,ms;
        for(auto i: nums)m[i]++;
        for(int i=1;i<=nums.size();i++)
        {
            if(m[i]==0)
                ms=i;
            if(m[i]>1)
                dup=i;
        }
        vector<int> v{dup,ms};
        return v;
    }
};