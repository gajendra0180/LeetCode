class Solution {
public:
    int dp[201][1001];
    int get(vector<int>&v,int index,int sum,int target){
        
        if(index>=v.size())
            return 0;
        if(sum==target)
            return 1;
        
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]+sum<=target){
                ans+=get(v,i,sum+v[i],target);
            }
        }
        return dp[index][sum] = ans;
    }
    
    int combinationSum4(vector<int>& v, int target) {
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof dp);
        return get(v,0,0,target);
    }
};