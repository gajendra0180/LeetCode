class Solution {
public:
    string baseNeg2(int n) {
        string res="";
        while(n)
        {
            int rem=n%-2;
            n=n/-2;
            if(rem<0)
            {
                rem=rem+2;
                n=n+1;
            }
           res=to_string(rem)+res;
        }
        if(res=="")
            return "0";
        return res;
    }
};