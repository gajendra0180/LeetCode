class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best_sum=nums[0],curr_sum=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(curr_sum+nums[i]<nums[i])
                curr_sum=nums[i];    
            else
                curr_sum+=nums[i];
            
            if(curr_sum>best_sum)
                best_sum=curr_sum;
        }
        return best_sum;
    }
};