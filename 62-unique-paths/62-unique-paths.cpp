class Solution {
public:
    int t[110][110];
    int get(int i,int j,int m,int n){
        if(i==m-1&&j==n-1)
            return 1;
        if(i>=m||j>=n)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        
        int p1=get(i+1,j,m,n);
        int p2=get(i,j+1,m,n);
        return t[i][j] = p1+p2;
    }
    
    int uniquePaths(int m, int n) {
        for(int i=0;i<110;i++){
            for(int j=0;j<110;j++){
                t[i][j]=-1;
            }
        }
        return get(0,0,m,n);
    }
};