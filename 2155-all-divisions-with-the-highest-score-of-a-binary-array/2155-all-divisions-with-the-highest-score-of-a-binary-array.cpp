class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        vector<int> left{0},right{0};
        int count=0;
        for(auto i:nums){
            if(i==0)
                count++;
            left.push_back(count);
        }
        count=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==1)count++;
            right.push_back(count);
        }
        int key=0;
        map<int,vector<int>> map1;
        for(int i=0;i<nums.size()+1;i++){
            int c_sum=left[i]+right[right.size()-1-i];
            key=max(key,c_sum);
            map1[c_sum].push_back(i);
        }
        return map1[key];
    }
};


