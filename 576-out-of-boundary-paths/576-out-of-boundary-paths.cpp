class Solution {
public:
    int x,y,mm;
    int arr[51][51][51];
      int mod = pow(10,9) + 7;
    int p(int i,int j,int move){
        
        if(i<0 || j<0  || i>=x || j>=y)
            return 1;
        
        if(move==0)
            return 0;
        
        if(arr[i][j][move]!=-1)
            return arr[i][j][move];
        
    return arr[i][j][move] = ((p(i-1,j,move-1)+p(i+1,j,move-1))%mod+(p(i,j-1,move-1)+p(i,j+1,move-1))%mod)%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        x=m,y=n,mm=maxMove;
        for(int i=0;i<51;i++){
            for(int j=0;j<51;j++){
                for(int k=0;k<51;k++){
                arr[i][j][k]=-1;}
            }
        }
        return p(startRow,startColumn,maxMove);      
    }
};