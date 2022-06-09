class Solution {
public:
    set<vector<int>> s;
    int countDistinct(vector<int>& nums, int k, int p) {
        for(int i=0;i<nums.size();i++){
            vector<int>temp{nums[i]};
            s.insert(temp);
            for(int j=i+1;j<nums.size();j++){
                temp.push_back(nums[j]);
                s.insert(temp);
            }
        }
        int res=0;
        for(auto i :s)
        {
            int c=0;
            for(auto j:i){
                if(j%p==0)
                    c++;
                if(c>k)
                    break;
            }
            if(c<=k)
                res++;
        }
        
        return res;
    }   
};