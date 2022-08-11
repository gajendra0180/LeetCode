class Solution {
public:
    vector<int>sq;
    int dp[100001][2];
    bool get(int n,int turn){
        if(n==0)
          return false;
        if(dp[n][turn]!=-1)
            return dp[n][turn];
        auto it=lower_bound(sq.begin(),sq.end(),n)-sq.begin();
        if(sq[it]!=n)it--;
        for(int i=it;i>=0;i--){
               if(!get(n-sq[i],turn^1))
                   return dp[n][turn] =true;
        }
        return  dp[n][turn] = false;
    }
    bool winnerSquareGame(int n) {
        int i=1;
        while(i*i<=100000){
            sq.push_back(i*i);
            i++;
        }
        memset(dp,-1,sizeof(dp));
        return get(n,1);
    }
};

