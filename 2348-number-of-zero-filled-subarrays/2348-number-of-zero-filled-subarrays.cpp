class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long i=0,res=0;
        while(i<nums.size()){
            if(nums[i]==0){
                int j=i;
                while(i<nums.size()&&nums[i]==0)
                    i++;
                res+=(i-j)*(i-j+1)/2;
            }
            else
                i++;
        }
        return res;
    }
};