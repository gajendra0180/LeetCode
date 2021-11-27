class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int xorr=0;
        for(auto i:nums)
            xorr|=i;
        return xorr*(1<<nums.size()-1);
    }
};