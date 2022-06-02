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
        
        for(int i=index;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            combination(candidates,i,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        combination(candidates,0,target,temp);
        return res;
        
    }
};