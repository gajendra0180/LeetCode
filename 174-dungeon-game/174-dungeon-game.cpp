class Solution {
public:
    map<pair<int,int>,int> m;
    int minn(int i,int j,vector<vector<int>>& dungeon)
    {
        
        if(i==dungeon.size()||j==dungeon[0].size())
            return 1e9;
        
        if(i==dungeon.size()-1&&j==dungeon[0].size()-1)
        {
            if(dungeon[i][j]<=0)
                return 1-dungeon[i][j];
            return 1;
        }
        if(m.find({i,j})!=m.end())
            return m[{i,j}];
        
        int ifWeGoRight=minn(i,j+1,dungeon);
        int ifWeGoDown=minn(i+1,j,dungeon);
        
        int minHealthReq=min(ifWeGoDown,ifWeGoRight)-dungeon[i][j];
         
        if(minHealthReq<=0)
             return m[{i,j}] =1;
        return m[{i,j}] = minHealthReq;
        
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
            return minn(0,0,dungeon);
    }
};