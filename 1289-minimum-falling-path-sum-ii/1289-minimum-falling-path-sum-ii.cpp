class Solution {
public:
    int arr[201][201];
    int m(vector<vector<int>>&grid,int row,int col){
        
        if(col<0 || col>=grid.size())
            return 1e9;
        
        if(row==grid.size()-1)
            return grid[row][col];
        
        int ans=INT_MAX;
        
        if(arr[row][col]!=-1)
            return arr[row][col];
        
        for(int i=0;i<grid.size();i++){
            if(i==col)
                continue;
            ans=min(ans,grid[row][col]+m(grid,row+1,i));
        }
        return arr[row][col] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans=INT_MAX;
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                arr[i][j]=-1;
            }
        }
        for(int i=0;i<grid.size();i++)
            ans=min(ans,m(grid,0,i));
        return ans;
    }
};