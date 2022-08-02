class Solution {
public:
    int dp[501][501];
    int solve(vector<int>&v,int index,int time){
        if(index==v.size())
            return 0;
        if(dp[index][time]!=-1)
            return dp[index][time];

        return dp[index][time]=max(v[index]*time+solve(v,index+1,time+1),solve(v,index+1,time));
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof dp);
        return solve(satisfaction,0,1);
    }
};