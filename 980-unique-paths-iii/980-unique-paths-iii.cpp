class Solution {
public:
       int emptySquares=0;
    int up(vector<vector<int>>&g,int i,int j,vector<vector<int>> vis,int sq){
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==-1 || vis[i][j]==1)
            return 0;
        
        if(g[i][j]==2){
            // cout<<sq<<endl;
            if(sq==emptySquares+1)
                return 1;
            return 0;
        }
        
        vis[i][j]=1;
        
        return up(g,i-1,j,vis,sq+1)+up(g,i,j-1,vis,sq+1)+up(g,i+1,j,vis,sq+1)+up(g,i,j+1,vis,sq+1);
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<int>>vis;
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[i].size();j++){
                 temp.push_back(0);
                 if(grid[i][j]==0)
                       emptySquares++;
            }
            vis.push_back(temp);
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1)
                    return up(grid,i,j,vis,0);
            }
        }
        return 0;
    }
    
};