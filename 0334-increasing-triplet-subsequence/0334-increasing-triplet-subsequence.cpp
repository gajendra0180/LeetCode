class Solution {
public:
     int lengthOfLIS(vector<int>& nums) {
        vector<int> res{nums[0]};
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>res.back())
                res.push_back(nums[i]);
            else
            {
                auto ind=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
                res[ind]=nums[i];
            }
        }
        return res.size();
    }
    bool increasingTriplet(vector<int>& nums) {
        return lengthOfLIS(nums)>=3?true:false;   
    }
};