class Solution {
public:
    int dp[13][10001];
    int get(vector<int>&coins,int amount,int index){
        
        if(index==coins.size()){
            if(amount==0)
                return 0;
            return 1e9;
        }
        
        if(dp[index][amount]!=-1)
            return dp[index][amount];

        if(amount>=coins[index])
            return dp[index][amount] = min(1+get(coins,amount-coins[index],index+1),min(get(coins,amount,index+1),1+get(coins,amount-coins[index],index)));
        return dp[index][amount] = get(coins,amount,index+1);
    }
    
    int coinChange(vector<int>& coins, int amount) {
      for(int i=0;i<13;i++){
          for(int j=0;j<10001;j++){
              dp[i][j]=-1;
          }
      }
        int res=get(coins,amount,0);
        if(res==1e9)
            return -1;
        return res; 
    }
};