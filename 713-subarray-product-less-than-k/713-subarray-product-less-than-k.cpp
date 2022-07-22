class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod=1,i=0,res=0;
        for(int j=0;j<nums.size();j++){
            
            prod*=nums[j];
            while(i<nums.size()&&prod>=k){
                prod/=nums[i];
                i++;
            }
            
            if(i>j)
                continue;
            
            res+=j-i+1;
        }
        return res;
    }
};