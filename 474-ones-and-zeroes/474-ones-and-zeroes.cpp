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
       vector<pair<int,int>> count;
    int f(vector<string>&strs,int m,int n,int index){
       
        if(m==0&&n==0 || index<0)
           return 0;
        
        if(arr[index][m][n]!=-1)
            return arr[index][m][n];
        
        
        if(count[index].first>m || count[index].second>n){
            return arr[index][m][n] = f(strs,m,n,index-1);
        }
        else
        {
            return  arr[index][m][n] = max(1+f(strs,m-count[index].first,n-count[index].second,index-1),f(strs,m,n,index-1));
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
     
        for(auto i:strs){
            vector<int>temp=getCount(i);
            count.push_back({temp[0],temp[1]});
        }
        return f(strs,m,n,strs.size()-1);
    }
};