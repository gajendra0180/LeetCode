class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gcd=numsDivide[0];
        int res=0;
        for(auto i:numsDivide)gcd=__gcd(gcd,i);
        sort(nums.begin(),nums.end());
        for(auto i:nums){
            if(gcd%i==0)
                return res;
            res++;
        }
        return -1;
    }
};