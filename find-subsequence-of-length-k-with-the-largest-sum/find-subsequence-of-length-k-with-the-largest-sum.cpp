class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        map<int,int> res;
        
        for(int i=0;i<k;i++)
            res[nums[i]]++;
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(res.find(temp[i])!=res.end())
            {
                res[temp[i]]--;
                if(res[temp[i]]==0)
                    res.erase(temp[i]);
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};