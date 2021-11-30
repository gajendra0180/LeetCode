class Solution {
public:
    string baseNeg2(int n) {
        string res="";
        while(n)
        {
            res=to_string(n&1)+res;
            n=-(n>>1);
        }
        if(res=="")
            return "0";
        else
            return res;
    }
};