class Solution {
public:
    int dp[100001][123];
int get(string &s, int &k, int index, char lastWord)
{
	if (index == s.size())
		return 0;
		
    if(dp[index][lastWord]!=-1){
        return dp[index][lastWord];
    }
    
	char ch;
	if (lastWord == ch)
	{
		return dp[index][lastWord] = max(1 + get(s, k, index + 1, s[index]), get(s, k, index + 1, ch));
	}
	else
	{
		// le skte h?
		if (abs(s[index] - lastWord) <= k)
		{
			return dp[index][lastWord] = max(1 + get(s, k, index + 1, s[index]), get(s, k, index + 1, lastWord));
		}
		else
			return dp[index][lastWord] =  get(s, k, index + 1, lastWord);
	}
}
    
    int longestIdealString(string s, int k) {
       char ch;
        for(int i=0;i<s.size();i++){
            for(int j=97;j<=122;j++){
                dp[i][j]=-1;
            }
        }
        memset(dp,-1,sizeof dp);
	return get(s, k, 0, ch);
    }
};