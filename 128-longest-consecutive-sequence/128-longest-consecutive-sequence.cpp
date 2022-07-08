class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()<=1)
            return nums.size();
        
        sort(nums.begin(),nums.end());
        int i=0,count=1,res=INT_MIN;
        while(i<nums.size()&&i+1<nums.size()){
            i++;
            if(nums[i]-nums[i-1]==1)
                count++;
            else if(nums[i]==nums[i-1])
            {
                
            }
            else
                count=1;
            res=max(res,count);
        }
        return res;
    }
};