class Solution {
public:
     int dp[1001][1001];
    
    int lcs(string &a,string &b,int i,int j){
        
        if(i>=a.size()||j>=b.size())
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j] = 1+lcs(a,b,i+1,j+1);
        else
            return dp[i][j] = max(lcs(a,b,i,j+1),lcs(a,b,i+1,j));
        
    }
    
    int longestPalindromeSubseq(string s) {
         for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=-1;
            }
        }
        string a=s;
        reverse(a.begin(),a.end());
        return lcs(s,a,0,0);
    }
};