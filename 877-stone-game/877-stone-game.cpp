class Solution {
public:
    bool get(int i,int j,vector<int>&v,int s1,int s2){
        if(i>j)
            return s1>s2;
        return get(i+1,j,v,s1+v[i],s2)||get(i,j-1,v,s1,s2+v[j]);
    }
    
    bool stoneGame(vector<int>& piles) {
       return get(0,piles.size()-1,piles,0,0);
    }
};