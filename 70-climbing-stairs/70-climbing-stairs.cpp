class Solution {
public:
    int t[50];
    int get(int n){
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        if(t[n]!=-1)
            return t[n];
        return t[n]=get(n-1)+get(n-2);
    }
    int climbStairs(int n) {
        for(int i=0;i<47;i++){
            t[i]=-1;
        }
        return get(n);
    }
};