class Solution {
public:
    int dp[1001][1001];
    int lcs(string &a,string &b,int x,int y){
        if(x<0 || y<0)
            return 0;
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        
        if(a[x]==b[y])
            return  dp[x][y] = 1+lcs(a,b,x-1,y-1);
        else
            return dp[x][y] = max(lcs(a,b,x-1,y),lcs(a,b,x,y-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof dp);
        return lcs(text1,text2,text1.size()-1,text2.size()-1);
    }
};