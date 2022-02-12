class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currBest=nums[0],overAllBest=nums[0];
        
        for(int i=1;i<nums.size();i++){
        
            if(nums[i]>currBest+nums[i])
                currBest=nums[i];
            else
                currBest+=nums[i];
            
            overAllBest=max(overAllBest,currBest);
        }
        
        return overAllBest;
    }
};