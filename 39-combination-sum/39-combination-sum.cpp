class Solution {
public:
    set<vector<int>>res;
    void combinations(int index,vector<int>&candidates,int target,vector<int> &temp){
        
        if(index>=candidates.size() || target<0)
            return;
        if(target==0){
            res.insert(temp);
            return;
        }
        combinations(index+1,candidates,target,temp);        
        temp.push_back(candidates[index]);
        combinations(index+1,candidates,target-candidates[index],temp);      
        combinations(index,candidates,target-candidates[index],temp);    
        temp.pop_back();
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>a;
        combinations(0,candidates,target,a);
        vector<vector<int>>ress;
        for(auto i:res){
            ress.push_back(i);
        }
        return ress;
        
    }
};