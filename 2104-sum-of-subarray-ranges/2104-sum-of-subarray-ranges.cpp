class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long res=0;
     for(int i=0;i<nums.size();i++){
            int maxx=nums[i],minn=nums[i];
             for(int j=i;j<nums.size();j++){
                 maxx=max(maxx,nums[j]);
                 minn=min(minn,nums[j]);
                 res+=maxx-minn;
             }
        }   
        return res;
    }
};

