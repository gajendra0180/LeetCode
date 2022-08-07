class Solution {
public:
    string s;
    int dp[100001];
    int get(int index){
        if(index==s.size())return 1;
        int mf=3;
        if(s[index]=='7'||s[index]=='9')mf=4;
        int res=0;
        if(dp[index]!=-1)
            return dp[index];
   
          long long currIndex = index, pressFrequency = 1, ans = 0;
        while(pressFrequency <= mf && s[currIndex] == s[index]) {
            ++currIndex;
            ++pressFrequency;
            res = (res%int(1e9+7) +get(currIndex) % int(1e9+7)) % int(1e9+7);
        }
        return dp[index]=res;
    }
    
    int countTexts(string pressedKeys) {
        s=pressedKeys;
        memset(dp,-1,sizeof dp);
        return get(0)%int(1e9+7);
    }
};

