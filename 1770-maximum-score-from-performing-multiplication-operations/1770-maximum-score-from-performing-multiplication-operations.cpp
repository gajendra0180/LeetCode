class Solution {
public:
    int dp[1001][1001];
    int get(vector<int>&n,vector<int>&m,int s,int i){
        if(i>=m.size())
            return 0;
        if(dp[s][i]!=INT_MIN)
            return dp[s][i];
        int takeStart=n[s]*m[i]+get(n,m,s+1,i+1);
        int val=n.back();
        n.pop_back();
        int takeLast=val*m[i]+get(n,m,s,i+1);
        n.push_back(val);
        return dp[s][i] = max(takeStart,takeLast);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                dp[i][j]=INT_MIN;
            }
        }
        return get(nums,multipliers,0,0);
        
    }
};