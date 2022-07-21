class Solution {
public:
    int t;
    vector<vector<int>> ct;
    int arr[101][21][101];
    int m(vector<int>&houses,int ind,int prevColorCol,int numberOfNeighbourhoods){
        if(ind==houses.size())
        {
            if(numberOfNeighbourhoods==t)
                return 0;
            return 1e9;
        }
        
        if( prevColorCol!=-1&&arr[ind][prevColorCol][numberOfNeighbourhoods]!=-1)
            return arr[ind][prevColorCol][numberOfNeighbourhoods];
        
        if(houses[ind]!=0){
            if(prevColorCol!=-1&&prevColorCol!=houses[ind]-1)
                numberOfNeighbourhoods++;
            return m(houses,ind+1,houses[ind]-1,numberOfNeighbourhoods);
        }
        
        int ans=1e9;
        int c=0;
        for(auto i:ct[ind]){
            if(prevColorCol!=-1&&c!=prevColorCol)
            {
                numberOfNeighbourhoods++;
                ans=min(ans,i+m(houses,ind+1,c,numberOfNeighbourhoods));
                numberOfNeighbourhoods--;
            }
            else
            {
                ans=min(ans,i+m(houses,ind+1,c,numberOfNeighbourhoods));
            }
            c++;
        }
        if(prevColorCol!=-1)
            arr[ind][prevColorCol][numberOfNeighbourhoods] = ans;
        return ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m1, int n, int target) {
        t=target;ct=cost;
        for(int i=0;i<101;i++){
            for(int j=0;j<21;j++){
                for(int k=0;k<101;k++){
                    arr[i][j][k]=-1;
                }
            }
        }
        int ans= m(houses,0,-1,1);
        if(ans==1e9)
            return -1;
        return ans;
    }
};

