class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return (n&n-1)==0;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>v;
        while(n){
            v.push_back(n%10);
            n=n/10;
        }
        sort(v.begin(),v.end());
        do{
            int len=v.size(),num=0;
            if(v[0]==0)
                continue;
            for(auto i:v){
                // cout<<i<<" ";
                num=num+i*pow(10,len-1);
                len--;
            }
            // cout<<num;
            // cout<<endl;
            if(isPowerOfTwo(num)){
                return true;
            }
        }
        while(next_permutation(v.begin(),v.end()));
        return false;
    }
};
