class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int a=0;a<nums.size();a++)
        {
            if(a>0&&nums[a]==nums[a-1])
                continue;
            int low=a+1,high=nums.size()-1;
            int req_sum=-nums[a];
            while(low<nums.size()-1&&high>0&&low<high)
            {
                int bPlusc=nums[low]+nums[high];
                if(bPlusc>-nums[a])
                {
                    high--;
                }
                else if(bPlusc<-nums[a])
                {
                    low++;
                }
                else if(bPlusc+nums[a]==0)
                {
                    res.push_back({nums[a],nums[low],nums[high]});
                    cout<<nums[a]<<" "<<nums[low]<<" "<<nums[high]<<endl;
                    low++;
                    while(low<nums.size()-1&&nums[low]==nums[low-1])
                        low++;
                    high--;
                    while(high>0&&nums[high]==nums[high+1])
                        high--;
                }
            }
        }
        return res;
    }
};