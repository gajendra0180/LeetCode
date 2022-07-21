class Solution {
public:
    int arr[101][101];
    int m(vector<vector<int>>&matrix,int row,int col){
        if(col<0 || col>=matrix.size())
            return 1e9;
        
        if(row==matrix.size()-1)
            return matrix[row][col];
        
        if(arr[row][col]!=-1)return arr[row][col];
        
        int leftD=matrix[row][col]+m(matrix,row+1,col-1);
        int D=matrix[row][col]+m(matrix,row+1,col);
        int rightD=matrix[row][col]+m(matrix,row+1,col+1);
    
        return arr[row][col] = min(leftD,min(D,rightD));
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                arr[i][j]=-1;
            }
        }
        for(int i=0;i<matrix.size();i++)
            ans=min(ans,m(matrix,0,i));
        return ans;
    }
};