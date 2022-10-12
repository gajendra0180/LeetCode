class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res{nums[0]};
        for(auto i:nums){
            auto index=lower_bound(res.begin(),res.end(),i)-res.begin();
            if(index>=res.size())
                res.push_back(i);
            else
                res[index]=i;
        }
        return res.size();
    }
};

