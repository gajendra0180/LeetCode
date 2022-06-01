class Solution {
public:
    static bool csort(vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]>b[1];
        else
        {
            return a[0]<b[0];
        }
    }
    
    int maxEnvelopes(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end(),csort);
        
        vector<int>res{nums[0][1]};
        
        for(int i=1;i<nums.size();i++){
            if(nums[i][1]>res.back())
            {
                    res.push_back(nums[i][1]);
            }
            else
            {
                auto ind=lower_bound(res.begin(),res.end(),nums[i][1])-res.begin();
                res[ind]=nums[i][1];
            }
        }
        return res.size();
    }   
};

