class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        set<int>s1,s2;
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int res=0;
        for(auto i:nums)s1.insert(i);
        for(auto i:numsDivide)s2.insert(i);
        
        for(auto i:s1){
            int can=1;
            for(auto j:s2){
                if(j%i!=0)
                {
                    res+=m[i];
                    can=0;
                    break;
                }
            }
            if(can==1)
                return res;
        }
        if(res==nums.size())
            return -1;
        return res;
    }
};