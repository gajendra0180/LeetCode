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

        for(int i=index+1;i<candidates.size();i++){
            
            if(i!=index+1){
                if(candidates[i-1]==candidates[i])
                continue;
            }
            
            temp.push_back(candidates[i]);
            combination(candidates,i,target-candidates[i],temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        
        for(int i=0;i<candidates.size();i++){
            if(i!=0&&candidates[i-1]==candidates[i])
                continue;
         vector<int>temp{candidates[i]};
            combination(candidates,i,target-candidates[i],temp);
        }
        
        return res;
        
    }
};