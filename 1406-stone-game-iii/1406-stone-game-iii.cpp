class Solution {
public:
    int dp[50001][2];
    int get(vector<int>&v,int index,int turn){
        if(index>=v.size())
            return 0;
        
        if(dp[index][turn]!=-1)
            return dp[index][turn];
        
            int sum1=0,sum2=0;
            if(index+1<v.size())
                sum1=v[index+1];
            if(index+2<v.size())
                sum2=v[index+2];
        
        if(turn){
            int one=v[index]+get(v,index+1,turn^1);
            int two=v[index]+sum1+get(v,index+2,turn^1);
            int three=v[index]+sum1+sum2+get(v,index+3,turn^1);
            return dp[index][turn] = max({one,two,three});
        }
        else
        {
            int one=get(v,index+1,turn^1)-v[index];
            int two=get(v,index+2,turn^1)-(v[index]+sum1);
            int three=get(v,index+3,turn^1)-(v[index]+sum1+sum2);
            return dp[index][turn] = min({one,two,three});
        }
    }
    
    string stoneGameIII(vector<int>& v) {
        memset(dp,-1,sizeof dp);
        int res= get(v,0,1);
        if(res<0)return "Bob";
        else if(res==0)return "Tie";
        return "Alice";
    }
};