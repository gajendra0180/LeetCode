class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int s=0;
        for(auto &i:nums){
            s+=i;
            i=s;
        }
        return nums;
    }
};