class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,me=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0)
            {
                me=nums[i];
                count++;
            }
            else if(nums[i]==me)
                count++;
            else
                count--;
        }
        return me;
    }
};