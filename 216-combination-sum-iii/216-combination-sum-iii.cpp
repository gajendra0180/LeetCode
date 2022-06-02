class Solution {
public:
      vector<vector<int>>res;
    void combination(vector<int>&candidates,int index,int target,vector<int>&temp,int chances){
        if(target==0 &&chances==1)
        {
            res.push_back(temp);
            return;
        }
        if(index>=candidates.size() || target<0 || chances<=0)
            return;

        for(int i=index+1;i<candidates.size();i++){
            
            temp.push_back(candidates[i]);
            combination(candidates,i,target-candidates[i],temp,chances-1);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
     
        vector<int>candidates{1,2,3,4,5,6,7,8,9};
        
          for(int i=0;i<candidates.size();i++){
         vector<int>temp{candidates[i]};
            combination(candidates,i,target-candidates[i],temp,k);
        }
        
        return res;
    }
};