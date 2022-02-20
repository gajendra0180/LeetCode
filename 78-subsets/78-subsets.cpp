class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0){
            return {{}};
        }
        int ch=nums[0];vector<int>subs;
        for(int i=1;i<nums.size();i++){
            subs.push_back(nums[i]);
        }
        vector<vector<int>> tres=subsets(subs);
        vector<vector<int>>fres;
        for(auto i:tres){
            vector<int> v1{},v2{ch};
            for(auto j:i)v1.push_back(j);            for(auto j:i)v2.push_back(j);

            fres.push_back(v1);            fres.push_back(v2);

        }
        return fres;
    }
};