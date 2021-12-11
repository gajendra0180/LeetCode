class Solution {
public:
    
    
    bool condition(long long int mid,long long int req,long long int a,long long int b,long long lcm)
    {
        long long int posx=mid/a+mid/b-(mid/lcm);
        if(posx<req)
            return false;
        return true;
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        long long int gcd=__gcd(a,b);
        long long int lcm=a*b/gcd;
       long long int left=1,right=1e18;
        while(left<right)
        {
            long long int mid=left+(right-left)/2;
            if(condition(mid,n,a,b,lcm))
                right=mid;
            else
                left=mid+1;
        }
        int mod=1e9+7;
        return left%mod;
    }
};