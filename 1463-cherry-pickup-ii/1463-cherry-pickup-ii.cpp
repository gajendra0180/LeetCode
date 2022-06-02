class Solution {
public:
    int arr[71][71][71];
    int cherry(int i1,int j1,int i2,int j2,vector<vector<int>>&grid){
        if(j1<0 || j2<0 || j2>=grid[0].size() || j1>=grid[0].size())
            return INT_MIN;
        
        if(i1==grid.size()-1 && i2==grid.size()-1){
             if(i1==i2&&j1==j2)
            return  grid[i1][j1];
        else
            return  grid[i1][j1]+grid[i2][j2];
        }
        
        
        if(arr[i1][j1][j2]!=-1)
            return arr[i1][j1][j2];
        
        int a=cherry(i1+1,j1-1,i2+1,j2-1,grid);
        int b=cherry(i1+1,j1-1,i2+1,j2,grid);
        int c=cherry(i1+1,j1-1,i2+1,j2+1,grid);
        int d=cherry(i1+1,j1,i2+1,j2-1,grid);
        int e=cherry(i1+1,j1,i2+1,j2,grid);
        int f=cherry(i1+1,j1,i2+1,j2+1,grid);
        int g=cherry(i1+1,j1+1,i2+1,j2-1,grid);
        int h=cherry(i1+1,j1+1,i2+1,j2,grid);
        int i=cherry(i1+1,j1+1,i2+1,j2+1,grid);
        

        int tempSum=0;
        if(i1==i2&&j1==j2)
            tempSum=grid[i1][j1];
        else
            tempSum=grid[i1][j1]+grid[i2][j2];
        
        return arr[i1][j1][j2] = tempSum + max(a,max(b,max(c,max(d,max(e,max(f,max(g,max(h,i))))))));
    
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        for(int i=0;i<71;i++){
            for(int j=0;j<71;j++){
                for(int k=0;k<71;k++){
                    arr[i][j][k]=-1;
                }
            }
        }
        return cherry(0,0,0,grid[0].size()-1,grid);
    }
};