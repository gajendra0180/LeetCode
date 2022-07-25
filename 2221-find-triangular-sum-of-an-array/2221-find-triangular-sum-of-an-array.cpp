class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=1){
            vector<int>v;
            for(int i=1;i<nums.size();i++){
                v.push_back((nums[i]+nums[i-1])%10);
            }
            nums=v;
        }
        return nums[0];
    }
};