class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int ans=1,sign=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<0 && sign!=-1)
            {
                sign=-1;
                ans++;
            }
            else if(nums[i]-nums[i-1]>0 && sign!=1){
                sign=1;
                ans++;
            }
        }
        return ans;
    }
};