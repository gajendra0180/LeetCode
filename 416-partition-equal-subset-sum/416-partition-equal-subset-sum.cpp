class Solution {
public:
    int t[210][20005];
    bool can(vector<int> &nums,int n,int target){
        if(n<0)
            return false;
        if(target<0)return false;
        if(target==0)return true;
        if(t[n][target]!=-1)return t[n][target];
        return t[n][target] = can(nums,n-1,target-nums[n]) || can(nums,n-1,target);
    }
    
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto i:nums)s+=i;
        if(s%2==0){
            for(int i=0;i<nums.size();i++)
                for(int j=0;j<s;j++)
                    t[i][j]=-1;
            return can(nums,nums.size()-1,s/2);
        }
        return false;
    }
};