class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int pos=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {pos=i;break;}
            m[nums[i]]=1;
        }
        int req=target-nums[pos];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==req&&i!=pos)
            {
                return{i,pos};
                break;
            }
        }
        return {};
    }
};