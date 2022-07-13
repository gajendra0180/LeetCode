class Solution {
public:
    bool sum(int s1,int s2,int s3,int s4,vector<int>&m,int index,int sum1){
        if(index==m.size())
            return (s1==s2&&s2==s3&&s3==s4);
        
        if(s1>(sum1/4) || s2>(sum1/4) || s3>(sum1/4) ||s4>(sum1/4))
            return false;
        
        return sum(s1+m[index],s2,s3,s4,m,index+1,sum1)||sum(s1,s2+m[index],s3,s4,m,index+1,sum1)||sum(s1,s2,s3+m[index],s4,m,index+1,sum1)||sum(s1,s2,s3,s4+m[index],m,index+1,sum1);
    }
    
    
    bool makesquare(vector<int>& matchsticks) {
        int sum1=0;
        for(auto i:matchsticks)
            sum1+=i;
        if(sum1%4!=0)
            return false;
        sort(matchsticks.begin(),matchsticks.end());
        reverse(matchsticks.begin(),matchsticks.end());
        return sum(0,0,0,0,matchsticks,0,sum1);
    }
};