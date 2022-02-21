class Solution {
public:
long long  exponentMod(long long  A, long long B, long long C)
{
    // Base cases
    if (A == 0)
        return 0;
    if (B == 0)
        return 1;
 
    // If B is even
    long y;
    if (B % 2 == 0) {
        y = exponentMod(A, B / 2, C);
        y = (y * y) % C;
    }
 
    // If B is odd
    else {
        y = A % C;
        y = (y * exponentMod(A, B - 1, C) % C) % C;
    }
 
    return (long long)((y + C) % C);
}
    
    int countGoodNumbers(long long n) {
        long long mod=1e9+7;
        if(n%2==0)
            return (exponentMod(5,n/2,mod)*exponentMod(4,n/2,mod))%mod;
        return (exponentMod(5,n/2+1,mod)*exponentMod(4,n/2,mod))%mod;
    }
};