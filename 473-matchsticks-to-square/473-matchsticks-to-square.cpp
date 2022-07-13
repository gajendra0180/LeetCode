class Solution {
public:
    
    bool can(vector<int>&m,vector<int>&s,int index,int sum){
        
        if(index==m.size())
        {
            if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
                return true;
            return false;
        }
        
        for(int i=0;i<4;i++){
            s[i]+=m[index];
            
            
            if(s[i]>sum/4.0){
                s[i]-=m[index];
                continue;
            }
            
            if(can(m,s,index+1,sum))
                return true;
            s[i]-=m[index];
        }    
        return false;
    }
    
    bool makesquare(vector<int>& m) {
        int s=0;
        sort(m.begin(),m.end(),greater<int>());
        for(auto i:m)
            s+=i;
        
        if(s%4!=0 || m.size()<4)
            return false;
        
        vector<int>ss{0,0,0,0};
        
        return can(m,ss,0,s);
            
    }
};