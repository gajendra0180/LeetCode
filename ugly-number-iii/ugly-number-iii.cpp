class Solution {
public:
    
    bool condition(long long int mid,long long int l1,long long int l2,long long int l3,long long int l4,long long int a,long long int b,long long int c,long long int req)
    {
        long long int n=mid/a+mid/b+mid/c-mid/l1-mid/l2-mid/l3+mid/l4;
        // cout<<mid<<" "<<n<<endl;
        if(n<req)
            return false;
        return true;
    }
    
    int nthUglyNumber(long long int n, long long int a, long long int b, long long int c) {
        long long int left=1,right=1e18;
        long long int lcm1=(a*b)/__gcd(a,b);
        long long int lcm2=(b*c)/__gcd(b,c);
        long long int lcm3=(a*c)/__gcd(a,c);
        long long int lcm4=a*lcm2/(__gcd(a,lcm2));
        // cout<<lcm1<<lcm2<<lcm3<<lcm4<<endl;
        while(left<right)
        {
            long long int mid=left+(right-left)/2;
            // cout<<left<<" @ "<<right<<endl;
            if(condition(mid,lcm1,lcm2,lcm3,lcm4,a,b,c,n))
                right=mid;
            else
                left=mid+1;
        }
        return left;
        
    }
};