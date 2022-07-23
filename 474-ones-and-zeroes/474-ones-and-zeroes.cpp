class Solution {
public:
    vector<int> getCount(string s){
        int one=0,zero=0;
        for(auto i:s){
            if(i=='1')
                one++;
            else
                zero++;
        }
        return {zero,one};
    }
    int arr[601][101][101];
    int f(vector<string>&strs,int m,int n,int index){
       
        if(m==0&&n==0 || index<0)
           return 0;
        
        if(arr[index][m][n]!=-1)
            return arr[index][m][n];
        
        vector<int>count=getCount(strs[index]);
        
        if(count[0]>m || count[1]>n){
            return arr[index][m][n] = f(strs,m,n,index-1);
        }
        else
        {
            return  arr[index][m][n] = max(1+f(strs,m-count[0],n-count[1],index-1),f(strs,m,n,index-1));
        }
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0;i<601;i++){
            for(int j=0;j<101;j++){
                for(int k=0;k<101;k++){
                    arr[i][j][k]=-1;
                }
            }
        }
        return f(strs,m,n,strs.size()-1);
    }
};