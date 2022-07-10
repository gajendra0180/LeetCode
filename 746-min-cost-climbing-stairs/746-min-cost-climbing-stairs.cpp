class Solution {
public:
    int dp[1001];
    int cost(vector<int>&c,int index){
        
        if(index>=c.size())
            return 0;
        
        if(dp[index]!=-1)
            return dp[index];
        
        return dp[index] = c[index]+min(cost(c,index+1),cost(c,index+2));
        
    }
    int minCostClimbingStairs(vector<int>& c) {
        for(int i=0;i<1001;i++)dp[i]=-1;
        int cost1=cost(c,0);
        for(int i=0;i<1001;i++)dp[i]=-1;
        int cost2=cost(c,1);
        return min(cost1,cost2);
    }
};