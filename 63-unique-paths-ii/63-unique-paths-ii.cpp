class Solution {
public:
        int arr[101][101];
    int up(int i,int j,vector<vector<int>>& g){
        
        if(i>=g.size() || j>=g[0].size() || g[i][j]==1)
            return 0;
        
        if(i==g.size()-1&&j==g[0].size()-1)
            return 1;
        
        if(arr[i][j]!=-1)
            return arr[i][j];
        
        return arr[i][j] =up(i+1,j,g)+up(i,j+1,g);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
           for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                arr[i][j]=-1;
            }
        }
        return up(0,0,g);
    }
};