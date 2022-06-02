class Solution {
public:
    int arr[201][1001];
    int combination(vector<int>&candidates,int index,int target,vector<int>&temp){
        
        if(target==0)
            return 1;
        
        if(index>=candidates.size() || target<0)
            return 0;
        
        if(arr[index][target]!=-1)
            return arr[index][target];
        
        int r=0;
        for(int i=0;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            r+=combination(candidates,i,target-candidates[i],temp);
            temp.pop_back();
        }
        return arr[index][target] = r;
    }
    
    int combinationSum4(vector<int>& candidates, int target) {
        vector<int>temp;
        for(int i=0;i<201;i++){
            for(int j=0;j<1001;j++){
                arr[i][j]=-1;
            }
        }
        return combination(candidates,0,target,temp);
    }
};