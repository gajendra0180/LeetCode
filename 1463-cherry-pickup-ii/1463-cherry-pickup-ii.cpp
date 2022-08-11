class Solution {
public:
    int dp[71][71][71];
    int get(vector<vector<int>>&grid,int x1,int y1,int y2){
        
        if(x1==grid.size())
            return 0;
        
        if(y1<0 || y2<0 || y1>=grid[0].size() || y2>=grid[0].size())
            return INT_MIN;
        
        int cherry=0;
        if(y1==y2)cherry+=grid[x1][y1];
        else
            cherry+=grid[x1][y1]+grid[x1][y2];
        
        if(dp[x1][y1][y2]!=-1)
            return dp[x1][y1][y2];
        
        int a=get(grid,x1+1,y1-1,y2-1);
        int b=get(grid,x1+1,y1-1,y2);
        int c=get(grid,x1+1,y1-1,y2+1);
        int d=get(grid,x1+1,y1,y2-1);
        int e=get(grid,x1+1,y1,y2);
        int f=get(grid,x1+1,y1,y2+1);
        int g=get(grid,x1+1,y1+1,y2-1);
        int h=get(grid,x1+1,y1+1,y2);
        int i=get(grid,x1+1,y1+1,y2+1);
        
        
        return dp[x1][y1][y2] = cherry + max({a,b,c,d,e,f,g,h,i});
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof dp);
        return get(grid,0,0,grid[0].size()-1);
    }
};