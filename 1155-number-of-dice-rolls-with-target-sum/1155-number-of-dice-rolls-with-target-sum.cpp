class Solution {
public:
    int dp[31][1001];
    int MOD=1e9+7;
    int get(int n,int k,int target){
        
        if(n==0 && target==0)
            return 1;
        if(n<=0 || target<=0)
            return 0;
        
        if(dp[n][target]!=-1){
            // cout<<"1";
            return dp[n][target];
        }
        
        int rs=0;
        for(int i=1;i<=k;i++){
            rs=(rs%MOD+get(n-1,k,target-i)%MOD)%MOD;
        }
        return dp[n][target] = rs;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof dp);
        return get(n,k,target);
    }

};

