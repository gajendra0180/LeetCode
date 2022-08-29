class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto i:nums){
            if(i>0)
                m[i]=1;
        }
        for(int i=1;i<1000000;i++){
            if(!m[i])
                return i;
        }
        return -1;
    }
};