class Solution {
public:
    int minCost(string c, vector<int>& t) {
            
        int i=0,j=0,fres=0;
        while(i<c.size()&&j<c.size()){
            int time=t[j],maxx=t[j];
            j++;
            while(c[j]==c[i]){
                time+=t[j];
                maxx=max(maxx,t[j]);
                j++;
            }
            fres+=time-maxx;
            i=j;
        }
        return fres;
    }
};