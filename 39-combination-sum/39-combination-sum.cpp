class Solution {
public:
    set<vector<int>>res;
    void combinations(int index,vector<int>&candidates,int target,vector<int> temp){
        
        if(index>=candidates.size() || target<0)
            return;
        if(target==0){
            res.insert(temp);
        }
        combinations(index+1,candidates,target,temp);        
        temp.push_back(candidates[index]);
        combinations(index+1,candidates,target-candidates[index],temp);      
        combinations(index,candidates,target-candidates[index],temp);    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        combinations(0,candidates,target,{});
        vector<vector<int>>ress;
        for(auto i:res){
            ress.push_back(i);
        }
        return ress;
        
    }
};