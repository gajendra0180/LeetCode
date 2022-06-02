class Solution {
public:
    vector<vector<int>>res;
    void combination(vector<int>&candidates,int index,int target,vector<int>&temp){
        
        if(target==0)
        {
            res.push_back(temp);
            return;
        }
        if(index>=candidates.size() || target<0)
            return;
        
        if(candidates[index]<=target){
            temp.push_back(candidates[index]);
            combination(candidates,index,target-candidates[index],temp);
            temp.pop_back();
        }
        combination(candidates,index+1,target,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        combination(candidates,0,target,temp);
        return res;
        
    }
};