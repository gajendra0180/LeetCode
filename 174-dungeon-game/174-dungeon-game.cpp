class Solution {
public:
    int arr[201][201];
    int h(vector<vector<int>>& g,int i,int j){
        
        if(i>=g.size() || j>=g[0].size())
            return 1e9;
        
        if(i==g.size()-1&&j==g[0].size()-1){
                if(g[i][j]>0)
                    return arr[i][j]=1;
            else
                return arr[i][j]=1-(g[i][j]);
        }
      if(arr[i][j]!=-1)
          return arr[i][j];
        int rightMeJaneKeLiyeItniHealthChahiye=h(g,i,j+1);
        int downMeJaneKeLiyeItniHealthChahiye=h(g,i+1,j);
        
        int healthRequired=min(rightMeJaneKeLiyeItniHealthChahiye,downMeJaneKeLiyeItniHealthChahiye)-g[i][j];
        
        if(healthRequired<=0)
            return arr[i][j]= 1;
        else
            return arr[i][j]=abs(healthRequired);
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){arr[i][j]=-1;}
        }
        return h(dungeon,0,0);
    }
};